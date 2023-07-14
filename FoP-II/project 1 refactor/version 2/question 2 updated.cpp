// This code prints a pattern by using a positive integer from the user.
// This code is written using structure and function.
#include <iostream>
using namespace std;

struct PatternPrinter {
    int num;
};

void printPattern(PatternPrinter);

int main() {

    PatternPrinter printer;
    cout << "Please enter a positive integer num: ";
    cin >> printer.num;
    printPattern(printer);
    return 0;
}

void printPattern(PatternPrinter print) {
        if (print.num <= 0) {
            cout << "Please enter a valid number" <<endl;
            return;
        }

        for (int i = print.num; i >= 0; i--) {
            for (int j = 0; j < print.num - i; j++) {
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
        for (int i = 1; i <= print.num; i++) {
            for (int j = 0; j < print.num - i; j++) {
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
    }

