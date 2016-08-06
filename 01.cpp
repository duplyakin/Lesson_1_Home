#include <iostream>
#include "logger.h"

#define SIZE 4

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 1");

  int buffer[SIZE];
  char ch;
  int index = 0;
  size_t size;

  while ((ch = getchar()) != '\n' && index < SIZE) {
    buffer[index++] = ch - '0';
  }
  size = index;

  for (int i = size - 1 ; i >= 0; i--) {
    printf("%d", buffer[i]);

  }

  DBG("[Lesson 1]: 1 [END]");
  return 0;
}
