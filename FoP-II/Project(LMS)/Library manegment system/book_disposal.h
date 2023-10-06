#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void dispose(){
    string line,book_id;
    ifstream file_book;
    ofstream file_temp;
    size_t substr_index;
    int choice,num_book;
    cout<<"Choose from the following:\n1.Delete all the data\n2.Delete specific data/book"<<endl;
    cin>>choice;
    if(choice==1){
            file_book.open("Books.txt");
            file_temp.open("temp.txt");
            file_book.close();
            file_temp.close();
            remove("Books.txt");
            rename("temp.txt","Books.txt");
        }
    else{
        cout<<"How many books you want to dispose? ";
        cin>>num_book;
        for(int i=0;i<num_book;i++){
        cout<<"Please enter book ID: ";
        cin>>book_id;
        file_book.open("Books.txt");
        file_temp.open("temp.txt");
        if(!file_book.is_open() || !file_temp.is_open()){
        cout<<"Couldn't open the file";

    }
    else{
       while(!file_book.eof()){
            getline(file_book,line);
            substr_index=line.find(book_id);
            if(substr_index==string::npos ){
                file_temp<<line<<endl;
            }
       }

        file_book.close();
        file_temp.close();
        remove("Books.txt");
        rename("temp.txt","Books.txt");
        }

        }

}
}

