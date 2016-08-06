#include <iostream>
#include <cmath>
#include "logger.h"

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 6");
  int i = 0;
  size_t N;
  std::cin >> N;

  int X[N];
  int Y[N];

  for (int i = 0; i < N; ++i) {
    std::cin >> X[i];
  }
  for (int i = 0; i < N; ++i) {
    std::cin >> Y[i];
  }
   
  float result = 0;

  while (i < N) {
    result += (std::abs(X[i] - Y[i]))*(std::abs(X[i] - Y[i]));
    ++i;
  }
  result = sqrt(result);

  std::cout << "destination is: " << result << std::endl;

  DBG("[Lesson 1]: 6 [END]");
  return 0;
}
