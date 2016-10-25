/*
 * Solution to Project Euler problem 25
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
 */

/* ALGORITHM: Below, final sumArray actually holds the 1000 digit Fibonacci number. It is not 
the best solution but it does not cheat using bigNumbers.

Output: 4782

real  0m0.113s
user  0m0.104s
sys 0m0.003s

on MacBook Pro 2015 i5
*/

#include <iostream>
#include "math.h"

int main()
{
  int tempArray[1000] = {0};
  tempArray[0] = 1;

  int sumArray[1000] = {0};
  sumArray[0] = 1;

  int index = 2;

  int oneSum = 0;
  int toBeAdded = 0;

  while(sumArray[999] == 0) {

    for( int i=0; i<1000; i++) {

      oneSum = tempArray[i] + sumArray[i] + toBeAdded;
      int remainder = oneSum % 10;
      toBeAdded = (oneSum - remainder)/10;
      tempArray[i] = sumArray[i];
      sumArray[i] = remainder;
      oneSum = 0;
    }
    index++;
  }

    std::cout << index << std::endl;

  return 0;
}