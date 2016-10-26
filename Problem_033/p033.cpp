/*
 * Solution to Project Euler problem 33 - Digit cancelling fractions
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it 
 * may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s. We shall consider fractions 
 * like, 30/50 = 3/5, to be trivial examples.
 * There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits 
 * in the numerator and denominator.
 * If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
 */

/* ALGORITHM: lowestCommon() function divides down a fracton to lowest common terms and returns the denominator.
It is clear that the fraction should be in the form: a/c = 10*a+b / 10*b+c. Rest is straightforward.

Output:   100

real	0m0.006s
user	0m0.002s
sys	0m0.002s

on MacBook Pro 2015 i5
*/

#include <iostream>
#include <cmath>

using namespace std;

int primes[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int lowestCommon(int num, int den) {

	for(int i=0; primes[i] <= num; i++) {
		while(num%primes[i] == 0 && den%primes[i] == 0) {
			num /= primes[i];
			den /= primes[i];
		}
	}
	return den;
}

int main() {

	int outputNumerator = 1, outputDenominator = 1;
    
	for(int b=1; b<10; b++) {
		for(int a=1; a<10; a++) {
			for(int c=a+1; c<10; c++) {

				int num = 10*a+b;
				int den = 10*b+c;

				if(num < den && lowestCommon(a, c) == lowestCommon(num, den)) {
					cout << num << "/" << den << endl;
					outputNumerator *= num;
					outputDenominator *= den;
				}
			}
		}
	}

    cout << lowestCommon(outputNumerator, outputDenominator) << endl;

    return 0;
}