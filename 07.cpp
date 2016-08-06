#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include "logger.h"

//coverts from any to any 

#define N 50
int power(int x, int y) {
  if (y==0) return 1;
  int i,rez=1;
  for (i=0; i<y; i++) {
      rez=rez*x;
  }
  return rez;
}

int rec(char c) {
  if (isdigit(c) != 0) {//Check if character is decimal digit: [0, 9]
    return atoi(&c);
  }
  if(isalpha(c) != 0) {//check if it is a charecter 
    return c-'A'+10;
  }
}

void backrec(int x)
{
  if (x < 10) {
    printf("%d", x);
    return;
  }
  if((x >= 10)&&(x < 36)) {
    printf("%c", 'A' + x - 10);
    return;
  }
}

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 7");

  char a[N], s[N];
  int c[N];
  int i = 0, j = 0;
  int n = 0, k = 0, z = 0;
  int w;

  for(i = 0; i < N; ++i) {
    a[i] = 0;
  }
  printf("Enter some number:\n");
  scanf("%d", &n);
  printf("Enter first system:\n");
  scanf("%s", &s);
  printf("Enter second system\n");
  scanf("%d", &k);
  //printf("%d \n", strlen(s));

  for (i = strlen(s)-1; i >= 0; i--) {
    //printf("%d ", i);
    z = z + power(n, strlen(s) - 1 - i) * rec(s[i]);
  }
  i = 0;
  while (z / k > 0) {
    c[i] = z % k;
    z = z / k;
    i++;
  }
  c[i] = z;
  for(j = i; j >= 0; j--) {
    backrec(c[j]);
  }
  
  DBG("[Lesson 1]: 7 [END]");
  return 0;
}