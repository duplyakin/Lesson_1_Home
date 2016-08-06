#include <iostream>
#include "logger.h"

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 3");
  size_t N;
  std::cin >> N;
  
  size_t max_length = 2*N;
  int left = N - 1;
  int right = N + 1;
  for (int i = 0; i < N; ++i) {
  	for (int j = 0; j < left; ++j) {
  		printf(" ");
  	}
  	for (int j = left + 1; j < right; ++j ) {
  		printf("*");
  	}
  	for (int j = right; j < max_length; ++j) {
  		printf(" ");
  	}
  	printf("\n");
  	--left;
  	++right;
  }

  DBG("[Lesson 1]: 3 [END]");
  return 0;
}
