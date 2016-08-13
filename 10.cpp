#include <iostream>
#include <cmath>
#include "logger.h"

long factorial(int n)
{
  long f = 1; 
  if((n==0)||(n==1))
    f = 1;
  else {
    for(int i = 1; i <= n; i++) {
      f *= i;
    }

  }    
  return f;       
}

double getFractional(double x) {
  return x - (int) x; 
}

double makeTwoSigns (double x) {
  //std::cout << "two signs: " << x - (getFractional(x*100))/100 << std::endl;
  return x - (getFractional(x*100))/100;
}

double taylor(double x) {
  double result = 0;
  double real_result = sin(x);
  double two_signs = makeTwoSigns(real_result);
  std::cout << "real sin:" << real_result << std::endl;
  for (int i = 0; ; ++i) {
    //std::cout << "factorial is: " << factorial(2 * i + 1) << std::endl;
    result += double(pow(-1, i) * pow(x, 2 * i + 1)) / factorial(2 * i + 1);
    if (two_signs == makeTwoSigns(result)) {
      std::cout << "taylor sin:" << result << std::endl;
      //std::cout << "diff is:" << result - real_result << std::endl;
      break;
    }
  }

}

int main(int argc, char** argv) {
  DBG("[Lesson 1]: 10");

  double x;
  std::cin >> x;
  x = fmod(x, 2 * M_PI);//найти соответствующий угол в пределах -2π <= x <= 2π
  double result = taylor(x);
  

  DBG("[Lesson 1]: 10 [END]");
  return 0;
}
