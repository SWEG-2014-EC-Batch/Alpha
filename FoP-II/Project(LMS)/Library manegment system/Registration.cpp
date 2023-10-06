#include<iostream>
#include<fstream>
#include<set>
#include<iomanip>
using namespace std;

struct book{
    string title,author,category,shelf_num,reg_date;
    float rating;
    string book_id;
    int quantity,av_quantity,num_raters;//available quantity
    };
bool operator<(const book& b1,const book& b2){
    return b1.title<b2.title;
    }
struct user{string name,sex;
    int contact_info;
};
    void register_book(){

    int num_book;//number of books to be registered
    cout<<"Please enter the number of books to be registered: ";
    cin>>num_book;
    cin.ignore();
   book book_reg[num_book];
    ofstream file_book("Books.txt",ios::out|ios::app );
    ifstream fin;
    fin.open("Books.txt");
    ofstream file_temp;
    file_temp.open("temp.txt",ios::out);
   string line;
   set<string>our_book;
    if(!file_book.is_open()){
        cout<<"Couldn't open the file"<<endl;
    }

    for(int i=0;i<num_book;i++){
        cout<<"Title of the book: ";
         getline(cin,book_reg[i].title);
        cout<<"Author: ";
        getline(cin,book_reg[i].author);
        cout<<"Category: ";
        cin>>book_reg[i].category;
        cout<<"Book ID: ";
        cin>>book_reg[i].book_id;
        cout<<"Shelf code: ";
        cin>>book_reg[i].shelf_num;
        cout<<"Registration date(in day-month-year format): ";
        cin>>book_reg[i].reg_date;
        cout<<"Quantity: ";
        cin>>book_reg[i].quantity;
        book_reg[i].av_quantity=book_reg[i].quantity;
        book_reg[i].rating=0;
        book_reg[i].num_raters=0;
        cin.ignore();
      file_book<<book_reg[i].title<<","<<book_reg[i].author<<","<<book_reg[i].category<<","<<
      book_reg[i].book_id<<","<<book_reg[i].shelf_num<<","<<book_reg[i].reg_date<<","<<book_reg[i].quantity
      <<","<<book_reg[i].av_quantity<<","<<book_reg[i].num_raters<<","<<book_reg[i].rating<<endl;
        }

    file_book.close();
if(!fin.is_open()){
    cout<<"couldn't open:"<<endl;
}
else {
        while (!fin.eof()){
   getline(fin,line);
    our_book.insert(line);


}
for(const auto& enter_book:our_book){
        file_temp<<enter_book<<endl;
    }
fin.close();
file_temp.close();
remove("Books.txt");
rename("temp.txt","Books.txt");
    }
    }

void user_reg(){
    ifstream fin;
    fin.open("User.txt");
    ofstream file_temp;
    file_temp.open("temp.txt",ios::out);
   string line;
   set<string>our_user;
    ofstream file_out("User.txt",ios::out | ios::app | ios::binary);
 int num_user;//number of users to be registered
 cout<<"Please enter the number of users to be registered: ";
 cin>>num_user;
 cin.ignore();
 user user_inf[num_user];
 if(file_out.is_open())
 for(int i=0;i<num_user;i++){
    cout<<"Name of user: ";
    getline(cin,user_inf[i].name);
    cout<<"Sex: ";
    cin>>user_inf[i].sex;
    cout<<"Contact information: ";
    cin>>user_inf[i].contact_info;
    cin.ignore();

    file_out<<user_inf[i].name<<","<<user_inf[i].sex<<","<<user_inf[i].contact_info<<endl;
 }
 file_out.close();
 if(!fin.is_open()){
    cout<<"couldn't open:"<<endl;
}
else {
        while (!fin.eof()){
   getline(fin,line);
    our_user.insert(line);


}
for(const auto& enter_user:our_user){
        file_temp<<enter_user<<endl;
    }
fin.close();
file_temp.close();
remove("User.txt");
rename("temp.txt","User.txt");
    }
}

