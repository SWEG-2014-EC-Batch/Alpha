#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
void stat_category();
void stat_sex();
void total_books();
void borrow_number();
void stat_choice(){
    int choice_num;
    cout<<"Choose for what category you want statistic:\n1.All books\n2.Sex\n3.Book Category\n4.Number of books borrowed"<<endl;
    cin>>choice_num;
    if(choice_num==1){
        total_books();
    }
    else if(choice_num==2){
        stat_sex();
    }
    else if(choice_num==3){
        stat_category();
    }
    else{
        borrow_number();
    }
}
void stat_sex(){
    ifstream file_s("User.txt");
    string line;
    size_t maleindex,femaleindex;
    int male=0,female=0;
    double percentf,percentm,total;
    if(!file_s.is_open()){
        cout<<"Coudln't open the file"<<endl;}
    while(!file_s.eof()){
        getline(file_s,line);
          for (char &casel : line) {
        casel = tolower(casel);
    }
        maleindex=line.find(",male");

        femaleindex=line.find("female");
        if(maleindex!=string::npos ){
            male=male+1;
        }
        if(femaleindex!=string::npos){
            female=female+1;
        }
    }
    file_s.close();

    total=male+female;
    percentf=(female*100)/total;
    percentm=(male*100)/total;
    cout<<"Number of Females = "<<female<<" ( "<<percentf<<"%)"<<endl;
    cout<<"Number of Males = "<<male<<" ( "<<percentm<<"%)"<<endl;
    cout<<"Total Users = "<<total<<endl;
    }

void stat_category(){
        ifstream file_cat;
        int number_book,num;
        float total;
        size_t index;
        string book_genre,line;

        cout<<"Number of genres you want to search for: "<<endl;
        cin>>num;
        cin.ignore();
        for(int i=0;i<num;i++){
            cout<<"Please enter the genre: "<<endl;
            getline(cin,book_genre);
            file_cat.open("Books.txt");

            number_book=0;
            total=0;
            while(!file_cat.eof()){
            getline(file_cat,line);
            if(line.length()>0){
                total=total+1;
            }
            for (char &casel : line) {
        casel = tolower(casel);
    }
            index=line.find(book_genre);
            if(index!=string::npos){
                number_book=number_book+1;
            }
            }
            cout<<"Number of books under the category "<<book_genre<<" = "<<number_book<<"( "<<(number_book*100)/total<<"%)"<<endl;
            file_cat.close();
        }
}

void total_books(){
            ifstream file_tot("Books.txt");
            int total=0,comma=0,foundit=0,size_cut=0,num_book=0;
            string line,av_books;
            while(!file_tot.eof()){
            getline(file_tot,line);

            comma=0;
            size_cut=0;

            foundit=0;
            for(int i=0;i<line.length();i++){
                if(line[i]==','){
                    comma=comma+1;
                }
                if(comma==7 ){
                    size_cut=size_cut+1;
                }
                if(comma==8 && foundit==0){
                    size_cut=size_cut-1;
                    num_book=stoi(line.substr(i-size_cut,size_cut));
                    foundit=1;
                }
            }

            if(line.length()>0){
            total=total+num_book;
            }
    }
        cout<<"The total number of available books = "<<total<<endl;
        file_tot.close();
}

void borrow_number(){
    ifstream file_brrw("Borrow.txt");
    int total=0;
    string line;
    if(!file_brrw.is_open()){
        cout<<"Couldn't open the file"<<endl;
    }
    else{
        while(!file_brrw.eof()){
            getline(file_brrw,line);
            if(line.length()>0){
                total=total+1;
            }
        }
        cout<<"The total number of books borrowed = "<<total<<endl;
    }
    file_brrw.close();
}
