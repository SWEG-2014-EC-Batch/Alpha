#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include "book_disposal.h"
#include "registration.h"
#include "borrow.h"
#include "overdue_notification.h"
#include "rating.h"
#include "stat.h"
#include<sstream>
#include<algorithm>
#include<cctype>
using namespace std;


void search_books();
void choice();
void all_book();
void all_user();
int main()
{
    char yes_no;
    do{
        choice();
        cout<<"Do you want to continue the program(y/n)? "<<endl;
        cin>>yes_no;

    }while (yes_no=='y');
    return 0;
}

void choice(){
        int choice_main,choice_num;
        cout<<"Choose from the following:\n1.Books\n2.Users\n3.Various statistical report"<<endl;
        cin>>choice_main;
        if(choice_main==1){
            cout<<"1.Book registration\n2.Check Availabilty\n3.Borrow\n4.Return Book\n5.Notification\n6.Dispose Book\n7.All Books"<<endl;
            cin>>choice_num;
            if(choice_num==1){
                register_book();
            }
            else if(choice_num==2){
                cin.ignore();
                search_books();

            }
            else if(choice_num==3){
                borrow_book();
            }
            else if(choice_num==4){
                return_book();
            }
            else if(choice_num==5){
                overdue_notification();
            }
            else if(choice_num==6){
                dispose();
            }
            else if(choice_num==7){
                all_book();
            }
            else{
                cout<<"Please enter valid input"<<endl;
            }
        }
    else if(choice_main==2){
            cout<<"1.User registration\n2.Rating\n3.All User's"<<endl;
            cin>>choice_num;
            if(choice_num==1){
                user_reg();
            }
            else if(choice_num==2){
                rate_book();
            }
            else {
                
            }

    }
    else{
        stat_choice();
    }
}

void search_books() {
    ifstream file_in("Books.txt", ios::in);
    string user_input;
    cout << "Please enter the book title, author, or category: ";
    getline(cin, user_input);
    transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);

    bool found = false;
    string line;
    while (getline(file_in, line)) {
        string temp = line;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if (temp.find(user_input) != string::npos) {
            vector<string> tokens;
            stringstream ss(line);
            string token;
            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }

            cout << "Title: " << tokens[0] << endl;
            cout << "Author: " << tokens[1] << endl;
            cout << "Category: " << tokens[2] << endl;
            cout << "Book ID: " << tokens[3] << endl;
            cout << "Shelf: " << tokens[4] << endl;
            cout << "Registration Date: " << tokens[5] << endl;
            cout << "Quantity Registered: " << tokens[6] << endl;
            cout << "Quantity Available: " << tokens[7] << endl;
            cout << "Number of raters: " << tokens[8] << endl;
            cout << "Rating: " << tokens[9] << endl;
            cout<<endl;
            found = true;
        }
    }

    file_in.close();

    if (!found) {
        cout << "Sorry, couldn't find any book with the inserted data" << endl;
    }
}


void all_book(){
        ifstream file_book("Books.txt");\
        string line;
        if(!file_book.is_open()){
            cout<<"Couldn't open the file"<<endl;
        }
        else{
                cout<<"Order of the column=Title,Author,Category,Book ID,Shelf,Registration Date,Registered Quantity,Available Quantity,Number of Raters,Rating"<<endl;
                cout<<endl;
                vector<vector<string>>data;
            while(getline(file_book,line)){
                vector<string> tokens;
                stringstream ss(line);
                string token;
                while(getline(ss,token,',')){
                    tokens.push_back(token);
                }
                data.push_back(tokens);
            }
                // Calculate column widths based on the maximum length of each column
        vector<int> columnWidths(data[0].size(), 0);
        for (const vector<string>& row : data) {
            for (size_t i = 0; i < row.size(); ++i) {
                if (row[i].length() > static_cast<size_t>(columnWidths[i])) {
                    columnWidths[i] = row[i].length();
                }
            }
        }

        // Print the data with proper column spacing
        for (const vector<string>& row : data) {
            for (size_t i = 0; i < row.size(); ++i) {
                cout << setw(columnWidths[i] + 10) << left << row[i]; // Adjust column width
            }
            cout << endl;
        }


        file_book.close();
        }
    void all_user(){
        ifstream file_book("User.txt");
        string line;
        if(!file_book.is_open()){
            cout<<"Couldn't open the file"<<endl;
        }
        else{
                cout<<"Order of the column = User name,Sex,Contact information"<<endl;
                cout<<endl;
                vector<vector<string>>data;
            while(getline(file_book,line)){
                vector<string> tokens;
                stringstream ss(line);
                string token;
                while(getline(ss,token,',')){
                    tokens.push_back(token);
                }
                data.push_back(tokens);
            }
                // Calculate column widths based on the maximum length of each column
        vector<int> columnWidths(data[0].size(), 0);
        for (const vector<string>& row : data) {
            for (size_t i = 0; i < row.size(); ++i) {
                if (row[i].length() > static_cast<size_t>(columnWidths[i])) {
                    columnWidths[i] = row[i].length();
                }
            }
        }

        // Print the data with proper column spacing
        for (const vector<string>& row : data) {
            for (size_t i = 0; i < row.size(); ++i) {
                cout << setw(columnWidths[i] + 5) << left << row[i]; // Adjust column width
            }
            cout << endl;
        }


        file_book.close();}
}

}



