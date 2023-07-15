#include <iostream>
 
using namespace std;
 
int main()
{
    double current_price,rate_inflation,current_year;
    int choice_num,num_year, spec_year,num_item;
    current_price=0;
    cout<<"This program allows users to calculate price for certain items for a specific or some number of years from now\n";
    cout<<"Note: Please use only appropriate numeric values as an answer for every question asked below"<<endl;
    cout<<"please enter the current price of the item"<<endl;
    cin>>current_price;
    cout<<"Please enter the inflation rate(in %) "<<endl;
    cin>>rate_inflation;
    cout<<"Please enter the current year"<<endl;
    cin>>current_year;
    cout<<"Please enter the number of years from now on  "<<endl;
    cin>>num_year;
    double price[2][num_year+1]={current_year};//price is the array for storing the prices of each year
    double diff[num_year];// diff is an array which stores the difference of prices for every successive year
    current_year=current_year+1;
 
 
    for(int i=0; i<2;i++){
        for(int j=0; j<num_year+1;j++){
            if (i==0){
                price[i][j+1]=current_year;
                current_year=current_year +1;
 
            }
            else{
                price[i][j]=current_price;
                current_price=current_price+((rate_inflation/100)*current_price);
            }
 
 
        }
    }
 
 
    //for diff array
 
    for(int i=0;i<num_year;i++){
                diff[i]=price[1][i+1]-price[1][i];
            }
 
    //printing diff
   
    cout<<"The difference of successive years price for the item is"<<endl;
        for(int j=0;j<num_year;j++){
            cout<<price[0][j]<<" and "<<price[0][j+1]<<": "<<diff[j]<<endl;
        }
   
       
       //taking in choice_num
       cout<<"Please enter 1 if you want to know the price of the item for specific year or enter 2 for "<<num_year<<" years"<<endl;
       cout<<"1. For specific year"<<endl;
       cout<<"2. For "<<num_year<<" years"<<endl;
       cin>>choice_num;
 
       if(choice_num==1){
        cout<<"Please enter the number of years from now on you want to know the price of the item"<<endl;
        cin>>spec_year;
        cout<<"Please enter the number of item"<<endl;
        cin>>num_item;
        cout<<"The price for "<<num_item<<" number of the item after "<<spec_year<<" year/years from now on(in "<<price[0][spec_year]<<")"<<" is "<<num_item*price[1][spec_year]<<endl;}
       
       
      else{
        for(int j=0;j<num_year+1;j++){
                cout<<price[0][j]<<": "<<price[1][j]<<endl;
 
            }
 
 
      }
      cout<<"Thank you for using this program!";
    return 0;
}
 


