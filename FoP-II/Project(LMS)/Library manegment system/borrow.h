#include <iostream>
#include<fstream>
#include<string>
#include "overdue_notification.h"

using namespace std;

struct borrowing_reader{
    string book_title,book_author,book_id,user_name,contact_info,date_borrowed;
};
int change_quantity(string book_id,int,int*);
void borrow_book(){
    int duration;
    ofstream brrw_inp("Borrow.txt",ios::out | ios::app);
    int num_usrs;//number of people borrowing
    cout<<"Number of books being borrowed: ";
    cin>>num_usrs;
    borrowing_reader borrow[num_usrs];
    cin.ignore();
    for(int i=0;i<num_usrs;i++){
    cout<<"Title of the book: ";
    getline(cin,borrow[i].book_title);
    cout<<"Author: ";
    getline(cin,borrow[i].book_author);
    cout<<"Book ID: ";
    cin>>borrow[i].book_id;
    cin.ignore();
    cout<<"User name: ";
    getline(cin,borrow[i].user_name);
    cout<<"Contact Information: ";
    cin>>borrow[i].contact_info;
    cout<<"Date borrowed(in day-month-year format): ";
    cin>>borrow[i].date_borrowed;
    if(change_quantity(borrow[i].book_id,0,&duration)!=1){
    brrw_inp<<borrow[i].book_title<<","<<borrow[i].book_author<<","<<borrow[i].book_id<<","<<borrow[i].user_name<<","<<borrow[i].contact_info<<","
    <<borrow[i].date_borrowed<<","<<duration<<endl;}
    cin.ignore();

    }
    brrw_inp.close();
}

void return_book(){
    int num_books; //Number of books to be returned
    ifstream file_read;
    int duration;
    ofstream temp;
    string book_id,inp_file,reader_info;
    size_t the_index_1,the_index_2;
    //string booksids[]
    int day,month,year;
    cout<<"Number of books being returned: ";
    cin>>num_books;
    cin.ignore();
    string booksids[num_books];
    for(int i=0;i<num_books;i++){
        file_read.open("Borrow.txt",ios::in );
       temp.open("Temp.txt",ios::out);
       cout<<"Please enter contact information: ";
        cin>>reader_info;
        cout<<"Please enter the book ID: ";
        cin>>book_id;
        cout<<"Please enter the current date in the following lines:"<<endl;
        cout<<"Day: ";
        cin>>day;
        cout<<"Month: "<<endl;
        cin>>month;
        cout<<"Year: ";
        cin>>year;
        cout<<"The overdue payment is "<<overdue_payment(book_id,reader_info,day,month,year)<<endl;
        while(!file_read.eof()){
            getline(file_read,inp_file);
            the_index_1=inp_file.find(book_id);
            the_index_2=inp_file.find(reader_info);
            if(the_index_1==string::npos && the_index_2==string::npos){
                temp<<inp_file<<endl;
            }
        }

        booksids[i]=book_id;
        file_read.close();
        temp.close();
        remove("Borrow.txt");
        rename("Temp.txt","Borrow.txt");

    }
    for(int i=0;i<num_books;i++){
        change_quantity(booksids[i],1,&duration);
    }

}

int change_quantity(string book_id,int check,int* duration){
    ifstream file_in("Books.txt",ios::in );
    ofstream file_temp("temp.txt");//temporary file to store a data
    string cut_string, file_inp;
    int quantity_chng;//stores the the changed quantity
    size_t substring;

    int c=0,comma=0,target_index,found_it=0,size_cut=0;
    if(file_in.is_open()){
        while(!file_in.eof()){
            getline(file_in,file_inp);
            substring=file_inp.find(book_id);
            if(substring!=string::npos){
                for(int i=0;i<file_inp.length();i++){
                    if(file_inp[i]==','){
                        comma+=1;
                    }
                    if(comma==7){
                      size_cut=size_cut+1;
                    }
                    if(comma==8 && found_it==0){
                    target_index=size_cut-1;
                    cut_string=file_inp.substr(i-target_index,size_cut-1);
                     quantity_chng=stoi(cut_string);
                    if(check==1){
                        quantity_chng=quantity_chng+1;
                    }
                    else{
                     quantity_chng=quantity_chng-1;
                     if(quantity_chng<100){
                        cout<<"Sorry! The available quantity is below the minimum requirement for borrowing"<<endl;
                        return 1;
                     }
                     else if(quantity_chng>200){
                        cout<<"The duration limit is 2 weeks"<<endl;
                        *duration=14;
                     }
                     else{
                        cout<<"The duration limit is 1 week"<<endl;
                        *duration=7;
                     }
                     }
                     cut_string=to_string(quantity_chng);

                     file_inp.replace(i-target_index,size_cut-1,cut_string);
                     found_it=1;
                    }
                }

                c=1;
            }
                file_temp<<file_inp<<endl;
        }
        file_in.close();
        file_temp.close();
        if(c==0){
            cout<<"Sorry, couldn't find any book with the inserted data";
        }
        remove("Books.txt");
        rename("temp.txt", "Books.txt");
    }
    else{
        cout<<"Couldn't open the file";
    }

return 0;
}
