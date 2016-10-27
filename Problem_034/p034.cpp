/*
 * Solution to Project Euler problem 34 - Digit factorials
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 * Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 */

/* ALGORITHM: What would be the maximum number that can be expressed in this way?
Think of 9s. 9! = 362.880
So for 9.999.999, there are 7 9s. And that is 2.540.160
Therefore possibly biggest number can be written in this way is 7 digits. However a 7 digits numer's factorial value can be 
maximum 2540160. So we can think this value as the upper limit.

Output:   40730

real	0m0.538s
user	0m0.529s
sys	0m0.003s

on MacBook Pro 2015 i5
*/

#include <iostream>

using namespace std;

int factorial(int n) {
	while(n>1) {
		return n * factorial(n-1);
	}
	return 1;
}

int calculateDigitFactorialSum(int n) {
	int sum = 0;
	while(n>0) {
		sum += factorial(n%10);
		n /= 10;
	}
	return sum;
}

int main() {

	long int sum = 0;

	for(int i=3; i<2540160; i++) {
		if(i == calculateDigitFactorialSum(i))
			sum +=i;
	}

    cout << sum << endl;

    return 0;
}