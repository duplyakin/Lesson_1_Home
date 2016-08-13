#include <iostream>
#include <cmath>
#include <cstdio>
#include "logger.h"

/*
1 january 1970 is 00:00:00
http://currentmillis.com/
*/
int leapYear(int year) {
  if (year % 4 != 0) {
    return 0;
  } else {
    if (year % 100 == 0 && year % 400 != 0) {
      return 0;
    } else {
      return 1;
    } 
  }
}

void date(long long timestamp) {

  int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int leep_months[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  std::cout << "timestamp is:" << timestamp << std::endl;

  long long milliseconds_in_day = 24*60*60*1000;
  int milliseconds_in_hour = 60*60*1000;
  int milliseconds_in_minute = 60*1000;

  long long tmp = timestamp;
  int i;
  for (i = 1970; ; ++i) {
    if (leapYear(i)) {
      tmp = tmp - 366*milliseconds_in_day;
    } else {
      tmp = tmp - 365*milliseconds_in_day;
    }
    if (tmp < 0) {
      break;
    }
    timestamp = tmp;
  }
  int year = i;
  //std::cout << "Year is:" << year << std::endl;

  tmp = timestamp;

  int leap_year = leapYear(year);
  for (i = 0; i < 12; ++i) {
    if (leap_year) {
      tmp -= leep_months[i]*milliseconds_in_day;
    } else {
      tmp -= months[i]*milliseconds_in_day;
    }

    if (tmp < 0) {
      break;
    }
    timestamp = tmp;
  }
  int month = i;
  //std::cout << "Month is:" << month << std::endl;

  tmp = timestamp;
  for (i = 0; ; ++i ) {
    tmp -= milliseconds_in_day;
    if (tmp < 0) {
      break;
    }
    timestamp = tmp;
  }
  int day = i;
  //std::cout << "Day is:" << day + 1 << std::endl;


  tmp = timestamp;
  for (i = 0; ; ++i ) {
    tmp -= milliseconds_in_hour;
    if (tmp < 0) {
      break;
    }
    timestamp = tmp;
  }
  int hour = i;
  //std::cout << "Hour is:" << hour << std::endl;


  tmp = timestamp;
  for (i = 0; ; ++i ) {
    tmp -= milliseconds_in_minute;
    if (tmp < 0) {
      break;
    }
    timestamp = tmp;
  }
  int minute = i;
  //std::cout << "Minute is:" << minute << std::endl;

  
  std::cout << day + 1 << " ";
  switch(month) {
    case 0: std::cout << "January"; break;
    case 1: std::cout  << "February"; break;
    case 2: std::cout  << "March"; break;
    case 3: std::cout  << "April"; break;
    case 4: std::cout  << "May"; break;
    case 5: std::cout  << "June"; break;
    case 6: std::cout  << "July"; break;
    case 7: std::cout  << "August"; break;
    case 8: std::cout  << "September"; break;
    case 9: std::cout  << "October"; break;
    case 10: std::cout << "November"; break;
    case 11: std::cout << "December"; break;
  }

  std::cout << " " << year << " " << hour + 3 << ":" << minute << std::endl;

}

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 15");
  long long timestamp = 1464765157274;
  date(timestamp);
  timestamp = 1471086555933;
  date(timestamp);
  timestamp = 1471087963075;
  date(timestamp);
  timestamp = 1471088619218;
  date(timestamp);



  DBG("[Lesson 1]: 15 [END]");
  return 0;
}
