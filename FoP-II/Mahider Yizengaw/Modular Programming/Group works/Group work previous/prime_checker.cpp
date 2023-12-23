# include <iostream>
using namespace std;

bool prime(int);

int main()
{
    // No argument is passed to prime()
    int num;
    cout << "Enter a positive integer enter to check: ";
    cin >> num;
    cout << prime(num);
    return 0;
}


// Return type of function is bool because boolean value is  returned.
bool prime(int a)
{

    int i;
    bool no_prime = 0;

    for(i = 2; i <= a/2; ++i)
    {
        if(a % i == 0)
        {
            no_prime = 1; 
            break;
        }
    }
    if(a == 1){
        return false;
    }

    else if (no_prime == 0 && a >= 1 && a <= 1000)
    {
        return true;
    }
    else if(no_prime == 1 && a >= 1 && a <= 1000)
    {
    return false;
    }
    else{
        exit (0);
    }
     
}
