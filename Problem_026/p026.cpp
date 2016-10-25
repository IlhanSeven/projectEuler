/*
 * Solution to Project Euler problem 26
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
 */

/* ALGORITHM: Below solution logically assumes that this number should be a prime. That definitely shortens 
the calculation time.

Output: 983

real  0m0.006s
user  0m0.002s
sys 0m0.002s

on MacBook Pro 2015 i5
*/


#include <iostream>
#include "math.h"

using namespace std;

bool isPrime(int n);
int countCycle(int n);

int main(){
  
  int temp=0, max = 0, output = 0;
  
  for(int i = 1; i<1000; i++) {
    if(isPrime(i)) {
      temp = countCycle(i);
      if(temp>max) {
        max = temp;
        output = i;
      }
    }
  }
  
  cout << output << "\t" << max << endl;
  return 0;
}

int countCycle(int n) {
  int count = 1;
  int remainder = 10 - (10/n)*n;
  while(remainder>1) {
    remainder = remainder*10 - (remainder*10/n)*n;
    count++;
  }
  return count;
}

bool isPrime(int n) {
  if(n == 1) {
    return false;
  } else if(n < 4) {
    return true;
  } else if(n % 2 == 0) {
    return false;
  } else if(n < 9) {
    return true;
  } else if(n % 3 == 0) {
    return false;
  } else {
    int r = floor(sqrt(n));
    int f = 5;
    while(f <= r) {
      if(n % f == 0) {
        return false;
      } else if(n % (f+2) == 0) {
        return false;
      }
      f += 6;
    }
  }
  return true;
}