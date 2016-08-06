#include <iostream>
#include <cmath>
#include "logger.h"

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 11");

  int year;
  std::cin >> year;

  if (year%4 != 0) {
  	std::cout << "no" << std::endl;
  } else {
  	if (year%100 == 0 && year%400 != 0) {
  		std::cout << "no" << std::endl;
  	} else {
  	  std::cout << "yes" << std::endl;
  	} 
  }

  DBG("[Lesson 1]: 11 [END]");
  return 0;
}