#include<iostream>
#include<iomanip>


using namespace std;

const int num_d = 9;
    
void accept(string name[],double mile[][num_d],const string names[], int i);
void cal(double mile[][num_d],int,int);
void printer(const string name[],double mile[][num_d],int);
void choice(string name[],int,double mile[][num_d],const string names[]);


int main(){
    int num;
    cout << "Please enter the numbers of runners: ";
    cin >> num;
    double mile[num][num_d];
    string name[num];
    string names[10] = {"names","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday","total miles","average miles"};

    for (int i = 0; i < num; i++){
        accept(name,mile,names,i);
        cal(mile,num_d,i);
    }
    choice(name,num,mile,names);
    
    cout << "THANK YOU FOR USING THIS PROGRAM!!";
    return 0;
}

void accept(string name[],double mile[][num_d],const string names[],int i){
    cin.ignore();
    cout<< "Please enter the name of the runner: ";
    getline(cin,name[i]);
    for(int j = 0;j < 7;j++){
        cout << "Please enter the number of miles run by " << name[i] << " on " << names[j+1] <<": ";
        cin >> mile[i][j];
    }
}

void cal(double mile[][num_d],int num_d,int i) {
    for(int j = 0;j < 7;j++){
        double total_m;
        total_m += mile[i][j];
        mile[i][7] = total_m;
    }
    double average_m = mile[i][7]/(num_d-2);
    mile[i][8] = average_m; 
}

void printer(const string name[],double mile[][num_d],int i){
    cout << left << setw(20) << name[i];
    cout << "\t";
    for(int j = 0;j < 9;j++){
        cout << left << setw(12) << mile[i][j];
    }
    cout << endl;
}
void choice(string name[],int num,double mile[][num_d],const string names[]){
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
                printer(name,mile,i);
            }
        } 
        else if (choice == 2) {
            cin.ignore();
            string name2;
            cout << "Enter the name of the runner: ";
            getline(cin, name2);

            bool found = false;
            for (int i = 0; i < num; i++) {
                if (name[i] == name2) {
                    for(int i = 0;i < 10;i++){
                       cout << left << setw(12) << names[i];
                       if (i == 0){
                          cout << "\t\t";
                        }
                    }
                    cout << endl;
                    printer(name,mile,i);
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

