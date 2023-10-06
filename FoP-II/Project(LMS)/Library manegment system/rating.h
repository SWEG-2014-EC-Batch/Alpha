#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
using namespace std;

void rate_book(){
        ifstream file_book;
        ofstream file_temp;
        string line,book_id;
        size_t the_index;
        int rate[5],num_cust=0,comma,foundIT,foundIT2,previous_custs,num_book;
        double prev_rating,curr_rating;
        int new_numCust,size_cut,rating_index;
        float new_rating;
        cout<<"Please enter the number of book to be rated: ";
        cin>>num_book;

        for(int i=0;i<num_book;i++){
        file_book.open("Books.txt",ios::in);
        file_temp.open("temp.txt",ios::out);
        new_numCust=0;
        previous_custs=0;
        prev_rating=0;
        size_cut=0;
        new_rating=0;
        curr_rating=0;
        num_cust=0;
        if(!file_book.is_open() || !file_temp.is_open()){
            cout<<"Couldn't open the file"<<endl;
        }
        cout<<"Please enter the book ID: ";
        cin>>book_id;
        comma=0;
        foundIT2=0;
        foundIT=0;
        for(int j=0;j<5;j++){
            cout<<"The number of people giving rating of "<<j+1<<endl;
            cin>>rate[j];
            num_cust=num_cust+rate[j];
        }
        while(!file_book.eof()){
            getline(file_book,line);
            the_index=line.find(book_id);
            if(the_index!=string::npos){
                for(int k=0;k<line.length();k++){
                    if(line[k]==','){
                        comma=comma+1;
                    }
                    if(comma==8){
                        size_cut=size_cut+1;
                    }
                    if(comma==9 && foundIT==0){

                        size_cut=size_cut-1;
                        previous_custs=stoi(line.substr(k-size_cut,size_cut));
                        prev_rating=stoi(line.substr(k+1,line.length()-(k+1)));
                        curr_rating=1*rate[0]+2*rate[1]+3*rate[2]+4*rate[3]+5*rate[4];
                        new_numCust=previous_custs+num_cust;
                        new_rating=(prev_rating*previous_custs+curr_rating)/(new_numCust);
                        new_rating=round(new_rating*10.0)/10.0;
                        ostringstream roundit;
                        roundit << fixed << setprecision(1) << new_rating;
                        string new_numCustS=to_string(new_numCust);
                        string new_ratingS=roundit.str();
                      line.erase(k-size_cut,line.length());
                      string commas=",";
                      line=line + new_numCustS+","+new_ratingS;

                        foundIT=1;
                    }
                }
            }
            if(line.length()>0){
            file_temp<<line<<endl;
            }
        }
        file_book.close();
        file_temp.close();
        remove("Books.txt");
        rename("temp.txt","Books.txt");
        }
    }
