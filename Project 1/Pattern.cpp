#include<iostream>

using namespace std;



int main() {
    int num;
    cout << "Please enter a positive integer num: ";
    cin >> num;
    if(num<=0){
     cout<<"Please enter a valid number";
     return 0;}
    for (int i = num; i >= 0; i--) {
        for (int j = 0; j < num - i; j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << j << " ";
        }
        for (int j = i - 1; j >= 0; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= num; i++) {
        for (int j = 0; j < num - i; j++) {
            cout << "  ";
        }
        for (int j = 0; j <= i; j++) {
            cout << j << " ";
        }
        for (int j = i - 1; j >= 0; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
