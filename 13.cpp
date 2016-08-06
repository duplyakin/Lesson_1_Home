#include <iostream>
#include <cmath>
#include <cstdio>
#include "logger.h"
using namespace std;

int day_of_week(int day,int month,int year)
  {
    unsigned long tmp,res;

    if(month>2)
      month++;
    else {
      month+=13;
      year-=1;
    }
    tmp=floor(365.25*year)+floor(30.6*month)+day-621050;
    res=tmp-floor(tmp/7)*7+1;

    return res;
  }

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 13");

  int res,day,month,year;
  char run; 
     
  cout << "Enter the year: ";  cin>>year;
  cout << "Enter the month: "; cin>>month;
  cout << "Enter the day: ";   cin>>day;

  res=day_of_week(day,month,year);

  switch(res) {
    case 1: cout<<endl << "This day is Monday"   << endl; break;
    case 2: cout<<endl << "This day is Tuesday"  << endl; break;
    case 3: cout<<endl << "This day is Wednesday" << endl; break;
    case 4: cout<<endl << "This day is Thursday" << endl; break;
    case 5: cout<<endl << "This day is Friday"   << endl; break;
    case 6: cout<<endl << "This day is Saturday" << endl; break;
    case 7: cout<<endl << "This day is Sunday"   << endl; break;
  }
  DBG("[Lesson 1]: 13 [END]");
  return 0;
}
