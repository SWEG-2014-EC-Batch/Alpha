#include <iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct emp_info{
    string name;
    int id_no, experience, hr_worked;
    double hourly_wage,hr_payment;
    char sex;

}emp1[10],emp2[10];


void str_data(){
    cin.ignore();
    for(int i=0;i<10;i++){
    cout<<"Please enter the name of the employee: ";
    getline(cin,emp1[i].name);
    cout<<"Please enter the sex of the employee: ";
    cin>>emp1[i].sex;
    cout<<"Please enter his/her id number: ";
    cin>>emp1[i].id_no;
    cout<<"Please enter his/her experience: ";
    cin>>emp1[i].experience;
    cout<<"Please enter his/her hourly wage: ";
    cin>>emp1[i].hourly_wage;
    cin.ignore();}
}

void writedata(){
    fstream outinf("employee.dat",ios::out | ios::binary | ios::app);
    str_data();
    int least,m,counter[310],arr_size,c;
    for(int j=0;j<10;j++){
        counter[j]=emp1[j].id_no;
    }
    arr_size=sizeof(counter)/sizeof(int);
    sort(counter, counter + arr_size);
   for(int j=0;j<10;j++){
    for(int k=0;k<10;k++){
        if(counter[j]==emp1[k].id_no){
            c=k;
        }
    }
    outinf.write((char *)&emp1[c],sizeof(emp1[c]));
    outinf.close();
    outinf.open("employee.dat",ios::out | ios::binary | ios::app);
   }
   outinf.close();


}

void readdata(){
    fstream empinf("employee.dat",ios::in | ios::binary);
    for(int h=0;h<10;h++){
        empinf.read((char *)&emp2[h], sizeof(emp2[h]));
        char c='n';
        do{
            cout<<"Please enter the number of hours "<<emp2[h].name<<" worked this month"<<endl;
            cin>>emp2[h].hr_worked;
            cout<<"The total pay for "<<emp2[h].name<<" is "<<emp2[h].hourly_wage*emp2[h].hr_worked<<endl;
            cout<<"Do you want to calculate for the next month?(y/n) ";
            cin>>c;
        }while(c=='y');
    }
    empinf.close();
}

void updatedata(){
    fstream empinf("employee.dat",ios::in | ios::binary);
    fstream outinf("employee.dat",ios::out | ios::binary);
    int choice;
    char c='n';
    for(int i=0;i<10;i++){
        empinf.read((char *)&emp2[i], sizeof(emp2[i]));
        do{
        cout<<"Do you want to update the(for "<<emp2[i].name<<")\n1. Hourly wage\n2. Experience\n3. Other numbers to exit? "<<endl;
        cin>>choice;

        if(choice==1){
            cout<<"Please enter new hourly wage(the previous value was "<<emp2[i].hourly_wage<<") for "<<emp2[i].name<<endl;
            cin>>emp2[i].hourly_wage;

        }
        else if(choice==2){
            cout<<"Please enter new hourly wage(the previous value was "<<emp2[i].experience<<") for "<<emp2[i].name<<endl;
            cin>>emp2[i].experience;

        }
        else{

            break;
        }
        cout<<"Do you want to continue the experience or hour wage update for "<<emp2[i].name<<"?(y/n) "<<endl;
        cin>>c;
    }while(c=='y');
    outinf.write((char *)&emp2[i], sizeof(emp2[i]));
    outinf.close();
    outinf.open("employee.dat",ios::out | ios::binary | ios::app);
    }
    empinf.close();
    }

void printdata(){
     fstream empinf("employee.dat",ios::in | ios::binary);
    for(int h=0;h<10;h++){
        empinf.read((char *)&emp2[h], sizeof(emp2[h]));
        cout<<"Name: "<<emp2[h].name<<endl;
        cout<<"Sex: "<<emp2[h].sex<<endl;
        cout<<"ID Number: "<<emp2[h].id_no<<endl;
        cout<<"Experience: "<<emp2[h].experience<<endl;
        cout<<"Hourly Wage: "<<emp2[h].hourly_wage<<endl;
}
empinf.close();
}

int main()
{
        int choice;
        char c='y';
        do{
        cout<<"Please choose what you want to do with the file\n1. Write to the file\n2. Read from the file\n3. Update the file\n4. Print the data in the file "<<endl;
        cin>>choice;
        if(choice==1){
        writedata();
        }
        else if(choice==2){
        readdata();}
        else if(choice==3){
            updatedata();
        }
        else if(choice==4){
            printdata();
        }
        cout<<"Do you want the program to continue?(y/n) ";
        cin>>c;
    }while(c=='y');
    return 0;
}
