#include <iostream>
#include "pro1lib.h"
using namespace std;

int main()
{
    int num_item;
    cout<<"Please enter the number of types of items: ";
    cin>>num_item;
    items array_item[num_item];
    accept_input(array_item,num_item);

    return 0;
}



