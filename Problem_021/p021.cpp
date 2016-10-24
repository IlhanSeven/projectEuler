/*
 * Solution to Project Euler problem 21
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 * Evaluate the sum of all the amicable numbers under 10000.
 */

/* ALGORITHM: You can use this sumOfDivisors() function. It is powerful.

Output: 31626

real	0m0.018s
user	0m0.015s
sys	0m0.002s

on MacBook Pro 2015 i5
*/

#include <iostream>
#include "math.h"

using namespace std;

int sumOfDivisors(int input) {
	int sqrtNum = sqrt(input) + 1;
	int sum = 0;
	for(int i = 1; i < sqrtNum; i++) {
		if(input % i == 0 && i*i != input) {
			sum += (i + input/i);
		}
		if(input % i == 0 && i*i == input)
			sum += i;
	}
	sum -= input;
	return sum;
}

int main() {
	
	int finalSum = 0;
	for(int i=4; i<10000; i++) {

		if(i == sumOfDivisors(i))
			continue;

		if(i == sumOfDivisors(sumOfDivisors(i)))
			finalSum = finalSum + i;
	}
	cout << finalSum << endl;

	return 0;
}
