#include <iostream>
#include <cmath>
#include "logger.h"

size_t gcd(size_t a, size_t b) {
  return b ? gcd(b, a % b) : a;
}

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 12");

  size_t a, b;
  std::cin >> a >> b;
  size_t result = gcd(a, b);
  std::cout << result;



  DBG("[Lesson 1]: 12 [END]");
  return 0;
}