#include <iostream>
#include "logger.h"

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 5");
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
   
  int result = 0;

  while (i < N) {
    result += X[i]*Y[i];
    ++i;
  }

  std::cout << "scalar is: " << result << std::endl;

  printf("(");
  const char* delimiter = "";
  for (int i = 0; i < N; ++i) {
    printf("%s", delimiter);
    printf("%d", X[i] + Y[i]);
    delimiter = ", ";
  }
  printf(") \n");



  DBG("[Lesson 1]: 5 [END]");
  return 0;
}
