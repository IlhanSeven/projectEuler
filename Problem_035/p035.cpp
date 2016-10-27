/*
 * Solution to Project Euler problem 35 - Circular primes
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
 * There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
 * How many circular primes are there below one million?
 */

/* ALGORITHM: Use an isPrime() function.
A function to calculate a number's number of digits.
A function to check if a number is a circular prime.

Output:   55

real	0m0.230s
user	0m0.223s
sys	0m0.003s

on MacBook Pro 2015 i5
*/

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);

int noOfDigits(int n) {
	int count = 0;
	while(n>0) {
		count += 1;
		n /= 10;
	}
	return count;
}

bool isCircular(int prime) {
	int count = 0;
	int digits = noOfDigits(prime);
	for(int i=0; i<digits; i++) {
		prime = prime/10 + (prime%10)*pow(10,(digits-1));
		if(isPrime(prime))
			count++;
	}
	if(count == digits)
		return true;
	return false;
}

int main() {

	int count = 0;
	for(int i=1; i<1000000; i++) {

		if(isPrime(i)) {
			if(isCircular(i))
				count++;
		}
	}
	cout << count << endl;

    return 0;
}

bool isPrime(int n) {
	if(n<=0) {
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