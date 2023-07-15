#include<iostream>
#include<iomanip>


using namespace std;

const int num_d = 9;

struct runner{
    string name;
    double mile[num_d];
    double total_m;
    double average_m;
};
    
void accept(runner& person, const string names[]);
void cal(runner &person);
void printer(const runner &person,int);
void choice(runner *person,const string names[],int num);


int main(){
    int num;
    cout << "Please enter the numbers of runners: ";
    cin >> num;

    runner *person = new runner[num];
    string names[10] = {"names","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday","total miles","average miles"};

    for (int i = 0; i < num; i++){
        accept(person[i],names);
        cal(person[i]);
    }
    choice(person,names, num);
    
    delete[] person;
    cout << "THANK YOU FOR USING THIS PROGRAM!!";
    return 0;
}

void accept(runner &person,const string names[]){
    cin.ignore();
    cout<< "Please enter the name of the runner: ";
    getline(cin,person.name);
    for(int j = 0;j < 7;j++){
        cout << "Please enter the number of miles run by " << person.name << " on " << names[j+1] <<": ";
        cin >> person.mile[j];
    }
}

void cal(runner &person) {
    for(int j = 0;j < 7;j++){
        person.total_m += person.mile[j];
        person.mile[7] = person.total_m;
    }
    person.average_m = person.mile[7]/(num_d-2);
    person.mile[8] = person.average_m; 
}

void printer(const runner &person,int num){
    cout << left << setw(20) << person.name;
    cout << "\t";
    for(int j = 0;j < 9;j++){
        cout << left << setw(12) << person.mile[j];
    }
    cout << endl;
}
void choice(runner *person,const string names[],int num){
    int choice;
    do {
        cout << "Enter;\n 0. to exit,\n 1. to display data for all runners,or\n 2. to display data for a specific runner: ";
        cin >> choice;
        if (choice == 1) {
            for(int i = 0;i < 10;i++){
                cout << left << setw(12) << names[i];
                if (i == 0){
                    cout << "\t\t";
                }
            }
            cout << endl;
            for (int i = 0; i < num; i++) {
                printer(person[i],num);
            }
        } 
        else if (choice == 2) {
            cin.ignore();
            string name;
            cout << "Enter the name of the runner: ";
            getline(cin, name);

            bool found = false;
            for (int i = 0; i < num; i++) {
                if (person[i].name == name) {
                    for(int i = 0;i < 10;i++){
                       cout << left << setw(12) << names[i];
                       if (i == 0){
                          cout << "\t\t";
                        }
                    }
                    cout << endl;
                    printer(person[i],num);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Runner not found."<<endl;
            }
        }
    } while (choice != 0);
}

