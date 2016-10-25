/*
 * Solution to Project Euler problem 30 - Digit fifth powers
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 */

/* ALGORITHM: -

Output:   443839

real	0m0.070s
user	0m0.066s
sys	0m0.002s

on MacBook Pro 2015 i5
*/

#include <iostream>
#include "math.h"

int main() {
	int sum = 0;
	for(int i=2; i<354294; i++) {
		int temp = 0, n = i;
		while(n!=0) {
			temp += pow((n%10), 5);
			n /= 10;
		}
		if(temp == i)
			sum += i;
	}
	std::cout << sum << std::endl;
	return 0;
}