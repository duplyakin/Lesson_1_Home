#include <iostream>
#include <cmath>
#include "logger.h"

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 9");
  int i = 0;
  int int_value = 0;
  long int long_value = 0; 

  while (int_value == long_value) {
    ++i;
    int_value = pow(2, i);
    long_value = pow(2, i);
    std::cout << "i: " << i << "  int_value: " << int_value << "  long_value: " << long_value << std::endl;
    
  }
  i--;
  std::cout << "i is: " << i << std::endl;
  std::cout << "max value of int is: " << pow(2, i) << std::endl;

  DBG("[Lesson 1]: 9 [END]");
  return 0;
}
