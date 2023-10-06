#ifndef overdue_notification_h
#define overdue_notification_h

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int daypassed(int currDay,int currMth,int currYear,int expDy,int expMth,int expYr);
void overdue_notification(){
    int currDay,currMonth,currYear,comma=0,dnt_repeat=0;//stores current date
    int dayF,monthF,yearF,durationF,dnt_repeat2=0,size_dur;//stores the day,month,year, and duration  from the file.
    int expected_dy,expected_mth,expected_yr; //expected book returning date
    int cmprDay,cmprMth,cmprYr, returned_val;
    ifstream file_brrw("Borrow.txt");
    string line;
    if(!file_brrw.is_open()){
        cout<<"Couldn't open the file"<<endl;
    }
    cout<<"Please enter the current date in the following lines"<<endl;
    cout<<"Day: ";
    cin>>currDay;
    cout<<"Month: ";
    cin>>currMonth;
    cout<<"Year: ";
    cin>>currYear;
    while(!file_brrw.eof()){
        getline(file_brrw,line);
        comma=0;
        dnt_repeat2=0;
        dnt_repeat=0;
        for(int i=0;i<line.length();i++){

            if(line[i]==','){
                comma=comma+1;
            }
            if(comma==5 && dnt_repeat==0){

                dayF=stoi(line.substr(i+1,2));

                monthF=stoi(line.substr(i+4,2));

                yearF=stoi(line.substr(i+7,4));
                dnt_repeat=1;
            }
            if(comma==6 && dnt_repeat2==0){
                size_dur=line.length()-(i+1);
                durationF=stoi(line.substr(i+1,size_dur));
                dnt_repeat2=1;
            }
        }

            expected_dy=dayF+durationF;
            if(expected_dy>30){
                expected_mth=monthF+1;
                expected_dy=expected_dy-30;
            }
            else{
                expected_mth=monthF;
            }
            if(expected_mth>12){
                expected_yr=yearF+1;
                expected_mth=expected_mth-12;
            }
            else{
                expected_yr=yearF;
            }
            returned_val=daypassed(currDay,currMonth,currYear,expected_dy,expected_mth,expected_yr);
            if(returned_val>0 && line.length()!=0){
                for(int i=0;i<line.length();i++){
                    if(line[i]==','){
                        line.replace(i,1," ");
                    }
                }
                cout<<line<<", day passed= "<<returned_val<<endl;
            }

            }
            file_brrw.close();

        }


double overdue_payment(string book_id,string contact_info,int currDay,int currMth, int currYr){
            ifstream pay_file("Borrow.txt");
            string line;
            double payment=0;
            int file_day,file_mth,file_year,expected_dy,expected_mth,expected_yr,duration;
            size_t for_book,for_contact;
            int comma=0,found_it=0,found_it2=0,size_dur;
            if(!pay_file.is_open()){
        cout<<"Couldn't open the file"<<endl;
            }
        while(!pay_file.eof()){
            getline(pay_file,line);
            for_book=line.find(book_id);
            for_contact=line.find(contact_info);
            comma=0;
            found_it=0;
            found_it2=0;
            if(for_book!=string::npos && for_contact!=string::npos){
                for(int i=0;i<line.length();i++){
                    if(line[i]==','){
                        comma=comma+1;
                    }

                    if(comma==5 && found_it==0){
                        file_day=stoi(line.substr(i+1,2));
                        file_mth=stoi(line.substr(i+4,2));

                        file_year=stoi(line.substr(i+7,4));
                        found_it=1;
                    }

                    if(comma==6 &&found_it2==0){
                        size_dur=line.length()-(i+1);
                        duration=stoi(line.substr(i+1,size_dur));
                        found_it2=1;
                    }

                }
            }
                expected_dy=file_day+duration;
            if(expected_dy>30){
                expected_mth=file_mth+1;
                expected_dy=expected_dy-30;
            }
            else{
                expected_mth=file_mth;
            }
            if(expected_mth>12){
                expected_yr=file_year+1;
                expected_mth=expected_mth-12;
            }
            else{
                expected_yr=file_year;
            }
        }
        payment=10*daypassed(currDay,currMth,currYr,expected_dy,expected_mth,expected_yr);
        return payment;
        pay_file.close();
}


int daypassed(int currDay,int currMonth,int currYear,int expected_dy,int expected_mth,int expected_yr){
    int cmprDay,cmprMth,dayDiff,cmprYear,mthDiff,daymthyear;
                    if(expected_yr==currYear){
                    if(expected_mth==currMonth){
                        cmprDay=currDay-expected_dy;
                //        cout<<"expected day= "<<expected_dy<<endl;
                        if(cmprDay>0){
                            return cmprDay;
                        }
                    }
                    else if(currMonth>expected_mth){
                        cmprMth=currMonth-expected_mth;
                        if(currDay>expected_dy){
                            dayDiff=currDay-expected_dy;
                            cmprDay=cmprMth*(30)+dayDiff;
                            return cmprDay;
                        }
                        else{
                            dayDiff=expected_dy-currDay;
                            cmprDay=cmprMth*(30)-dayDiff;
                            return cmprDay;
                        }
                    }

                    }
            else if(currYear>expected_yr){
                cmprYear=currYear-expected_yr;
                if(currMonth>expected_mth){
                    mthDiff=currMonth-expected_mth;
                    daymthyear=cmprYear*(365)+mthDiff*(30);
                    if(currDay>expected_dy){
                            dayDiff=currDay-expected_dy;
                            cmprDay=daymthyear+dayDiff;
                            return cmprDay;
                        }
                    else{
                        dayDiff=expected_dy-currDay;
                        cmprDay=daymthyear-dayDiff;
                        return cmprDay;
                    }
                }
                else{
                    mthDiff=expected_mth-currMonth;
                    daymthyear=cmprYear*(365)-(mthDiff*(30));
                    if(currDay>expected_dy){
                            dayDiff=currDay-expected_dy;
                            cmprDay=daymthyear+dayDiff;
                            return cmprDay;
                        }
                    else{
                        dayDiff=expected_dy-currDay;
                        cmprDay=daymthyear-dayDiff;
                        return cmprDay;
                    }
                }
           }
           return 0;
}
#endif overdue_notification_h
