/*
 * Solution to Project Euler problem 28 - Number spiral diagonals
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way as in Problem 28?
 */

/* ALGORITHM: If you look at it closely you will find a math equation which makes this solution very easy.
And that is in every (i-1)th circle the sum of the numbers at the corners is calculated in the following way:
4*i*i - 6*(i-1)

Output:   669171001

real  0m0.006s
user  0m0.001s
sys 0m0.002s

on MacBook Pro 2015 i5
*/

#include <iostream>

int main()
{
  int sum = 0;
  for(int i = 1001; i>1; i-=2) {
    sum += (4*i*i - 6*(i-1));
  }
  std::cout << sum+1 << std::endl;

  return 0;
}