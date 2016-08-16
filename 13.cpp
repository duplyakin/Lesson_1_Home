#include <iostream>
#include <cmath>
#include <cstdio>
#include "logger.h"

/*
Нужно задать начальную дату. Считается, что 01.01.1800 - это среда.
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

//-----------------------------------------------
//01.01.1800 is Wednesday
int start_year = 1800;
int start_month = 1;
int start_day = 1;

unsigned long tmp = 2;
//-----------------------------------------------

int dayOfWeekPlus(int day,int month,int year) {
  unsigned long res;
  int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int leep_months[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  char days[7][10] = {"Monday", "Tuesday", "Wednesday", "Thuesday", "Friday", "Saturday", "Sunday"};
  
  for ( int i = start_year; i < year; ++i ) {
    tmp += 365 + leapYear(i);  
  }

  int leap_year = leapYear(year);
  for ( int i = 0; i < month - 1; ++i ) {
    if (leap_year) {
      tmp += leep_months[i];
    } else {
      tmp += months[i];
    }
  }

  res = (tmp + day) % 7; 

  return res;
}

int dayOfWeekMinus(int day,int month,int year) {
  unsigned long res;
  int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int leep_months[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  char days[7][10] = {"Monday", "Tuesday", "Wednesday", "Thuesday", "Friday", "Saturday", "Sunday"};
  
  for ( int i = start_year; i < year; ++i ) {
    tmp -= 365 + leapYear(i);  
  }

  int leap_year = leapYear(year);
  for ( int i = 0; i < month - 1; ++i ) {
    if (leap_year) {
      tmp -= leep_months[i];
    } else {
      tmp -= months[i];
    }
  }

  res = (tmp + day) % 7; 

  return res;
}

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 13");

  int res,day,month,year;
  char run; 
     
  std::cout << "Enter the year: ";  std::cin >> year;
  std::cout << "Enter the month: "; std::cin >> month;
  std::cout << "Enter the day: ";   std::cin >> day;

  if (year < start_year) {
    res = dayOfWeekMinus(day,month,year);
  } else {
    res = dayOfWeekPlus(day,month,year);
  }

  dayOfWeekPlus(day,month,year);

  switch(res) {
    case 0: std::cout << std::endl << "This day is Sunday"   << std::endl; break;
    case 1: std::cout << std::endl << "This day is Monday"   << std::endl; break;
    case 2: std::cout << std::endl << "This day is Tuesday"  << std::endl; break;
    case 3: std::cout << std::endl << "This day is Wednesday" << std::endl; break;
    case 4: std::cout << std::endl << "This day is Thursday" << std::endl; break;
    case 5: std::cout << std::endl << "This day is Friday"   << std::endl; break;
    case 6: std::cout << std::endl << "This day is Saturday" << std::endl; break;
  }

  DBG("[Lesson 1]: 13 [END]");
  return 0;
}
