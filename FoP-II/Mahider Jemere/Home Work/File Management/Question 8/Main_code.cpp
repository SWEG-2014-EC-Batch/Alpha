#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    char c;
    int i=97,counter;
    ifstream file("Sheet5Ex5.cpp",ios::in);
    if(!file.is_open()){
        cout<<"Couldn't open a file";
    }
    else{
       cout<<"Character            Occurrence"<<endl;
       while(i<123){
        counter=0;
        while(!file.eof()){
            file.get(c);

            if(i==(int)c){
                counter=counter+1;
            }

        }
        file.close();
        cout<<(char)i<<"                          "<<counter<<endl;
        i=i+1;
        file.open("Sheet5Ex5.cpp",ios::in);
       }

    }
    file.close();
    return 0;
}
