#include<iostream>
using namespace std;

struct items{
     string name;
     double current_price,rate_inflation,current_year, *price_ptr,*diff_ptr;
     int choice_num,num_year, spec_year,num_item,size_price;

};
 char last_choice='y';
void order_price(items[],int);
void display_diff(items [],int);
void display_price(items[],int);

void accept_input(items item1[], int arr_size){
    for (int i=0;i<arr_size;i++){
    cout<<"Please enter the name of the item: ";
    cin>>item1[i].name;
    cout<<"please enter the current price of the item"<<endl;
    cin>>item1[i].current_price;
    cout<<"Please enter the inflation rate"<<endl;
    cin>>item1[i].rate_inflation;
    cout<<"Please enter the current year"<<endl;
    cin>>item1[i].current_year;
    cout<<"Please enter the number of years from now on  "<<endl;
    cin>>item1[i].num_year;
    item1[i].size_price=2*(item1[i].num_year+1);
    item1[i].price_ptr= new double[item1[i].size_price];
    item1[i].diff_ptr=new double[item1[i].num_year];
    cin.ignore();
    }

    order_price(item1,arr_size);

   display_diff(item1,arr_size);
   do{
    display_price(item1, arr_size);
    }while(last_choice=='y');
     cout<<"Thank you for using this program!";
    for(int i=0;i<arr_size;i++){
        delete[] item1[i].price_ptr;
      delete[] item1[i].diff_ptr;
    }

}

void order_price(items item1[],int arr_size){
    for(int i=0;i<arr_size;i++){
            int c=0;
           // int size_index=2*(item1[i].num_year+1);
        for(int j=0;j<item1[i].size_price;j++){
            if(j<item1[i].num_year+1){
                item1[i].price_ptr[j]=item1[i].current_year;
                item1[i].current_year=item1[i].current_year+1;
            }
            else{
                item1[i].price_ptr[j]=item1[i].current_price;

                item1[i].current_price=item1[i].current_price+((item1[i].rate_inflation/100)*item1[i].current_price);
            }
        }
    }

    //for difference array
    for(int i=0;i<arr_size;i++){
        for(int j=0;j<item1[i].num_year;j++){
            item1[i].diff_ptr[j]=item1[i].price_ptr[j+2+item1[i].num_year]-item1[i].price_ptr[item1[i].num_year+j+1];
        }
    }
}



void display_diff(items item1[],int arr_size){
    //printing diff
    for(int i=0;i<arr_size;i++){
    cout<<"The difference of successive years price for "<<item1[i].name<<" is:"<<endl;
   // cout<<"for the first index: "<<item1[0].price_ptr[0];
        for(int j=0;j<item1[i].num_year;j++){
            cout<<item1[i].price_ptr[j]<<" and "<<item1[i].price_ptr[j+1]<<": "<<item1[i].diff_ptr[j]<<endl;
        }}

}

void display_price(items item1[], int arr_size){
    for(int i=0;i<arr_size;i++){
     //taking in choice_num
       cout<<"Please enter 1 if you want to know the price of the "<<item1[i].name<<" for specific year or enter 2 for "<<item1[i].num_year<<" years"<<endl;
       cout<<"1. For specific year"<<endl;
       cout<<"2. For "<<item1[i].num_year<<" years"<<endl;
       cout<<"Any key other than 1 and 2 to exit"<<endl;
       cin>>item1[i].choice_num;

       if(item1[i].choice_num==1){
        cout<<"Please enter the number of years from now on you want to know the price of the item "<<endl;
        cin>>item1[i].spec_year;
        cout<<"Please enter the number of item"<<endl;
        cin>>item1[i].num_item;
        cout<<"The price for "<<item1[i].num_item<<" number of the item after "<<item1[i].spec_year<<" year/years from now on(in "<<item1[i].price_ptr[item1[i].spec_year]<<")"<<" is "<<item1[i].num_item*(item1[i].price_ptr[item1[i].num_year+item1[i].spec_year])<<endl;}


      else if(item1[i].choice_num==2){

        for(int j=0;j<item1[i].num_year+1;j++){
                cout<<item1[i].price_ptr[j]<<": "<<item1[i].price_ptr[item1[i].num_year+j+1]<<endl;

            }
      }
      else{
        last_choice='n';
        break;
      }

    }
}
