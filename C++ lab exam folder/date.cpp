#include<iostream>
using namespace std;
class DATE {
private:
    int day,month,year;
public:
    DATE(int d,int m,int y) {
        day=d;
        month=m;
        year=y;
    }
    int getDay() {return day;}
    int getMonth() {return month;}
    int getYear() {return year;}
    int operator -(const DATE &other) {
        int days1=day+(month*30)+(year*365);
        int days2=other.day+(other.month*30)+(other.year*365);
        return days1-days2;
    }
    DATE operator +(int days) {
        int TotalDays=day+(month*30)+(year*365)+days;
        int newYear=TotalDays/365;
        TotalDays%=365;
        int newMonth=TotalDays/30;
        int newDay=TotalDays%30;
        return DATE(newDay,newMonth,newYear);
    }
};
int main() {
    int d1,m1,y1,d2,m2,y2;
    cout<<"Enter the first date (dd mm yy): ";
    cin>>d1>>m1>>y1;
    cout<<"Enter the second date (dd mm yy): ";
    cin>>d2>>m2>>y2;
    DATE date1(d1,m1,y1);
    DATE date2(d2,m2,y2);
    int no_of_days=date1-date2;
    cout<<"Difference in days: "<<no_of_days<<endl;
    int additional_days;
    cout<<"Enter the number of days to add to the second date: ";
    cin>>additional_days;
    DATE result_date = date2 + additional_days;
    cout<<"New data after days: "<<result_date.getDay()<<"/"<<result_date.getMonth()<<"/"<<result_date.getYear()<<endl;
    return 0;
}