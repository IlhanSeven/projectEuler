/*
 * Solution to Project Euler problem 27 - Quadratic primes
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: Find the product of the coefficients, a and b, for the quadratic expression 
 * that produces the maximum number of primes for consecutive values of n, starting with n = 0.
 */

/* ALGORITHM: Powerful isPrime() function and note that a starts from -b[].

Output:   -59231

real  0m0.025s
user  0m0.020s
sys 0m0.002s

on MacBook Pro 2015 i5
*/


#include <iostream>
#include <vector>
#include "math.h"

using namespace std;

bool isPrime(int n);

int main() {

  vector<int> b;
  for(int i=1; i<1000; i++)
    if(isPrime(i))
      b.push_back(i);
  
  int temp = 0, countPrime = 0, n = 0;
  int finala, finalb;
  
  for(int j=1; j<b.size(); j++) {
    for(int a=-b[j]; a <1000; a++) {
      while(isPrime(n*(n+a)+b[j])) {
        temp++;
        n+=1;
      }
      if(temp>countPrime) {
        countPrime = temp;
        finala = a;
        finalb = b[j];
      }
      temp = 0;
      n = 0;
    }
  }
  
  cout << finala * finalb << endl;
  return 0;
}

bool isPrime(int n) {
  if(n < 1) {
    return false;
  } else if(n == 1) {
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