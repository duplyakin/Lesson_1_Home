#include <iostream>
#include "logger.h"

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 2");

  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j < 10; ++j) {
      printf("%d*%d = %d.10 ", i, j, i*j);
    }
    printf("\n");
  }

  DBG("[Lesson 1]: 2 [END]");
  return 0;
}
