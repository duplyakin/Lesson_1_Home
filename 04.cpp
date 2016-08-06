#include <iostream>
#include "logger.h"

long long power(int N, int a) {
  if (a == 0) {
    return 1;
  }
  long long result = 1;
  while (a > 1) {
    result =  result*N;
    --a;
  } 
  return result;
}

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 4");
  int N;
  int a;
  std::cin >> N >> a;
  std::cout << power(N, a) << std::endl;  

  DBG("[Lesson 1]: 4 [END]");
  return 0;
}
