/*
 * Solution to Project Euler problem 12
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * Problem: What is the value of the first triangle number to have over five hundred divisors?
 */

/* ALGORITHM:

Output: 76576500

real    0m0.006s
user    0m0.001s
sys     0m0.003s

on MacBook Pro 2015 i5
*/

#include <iostream>
#include <string>
#include <vector>
#include "math.h"

using namespace std;

bool isPrime(int n);

int main() {
	// primeNumbers
	int primeNumbers[43] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,
						  97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191};
	int count2 = 0, count3 = 0, count5 = 0, count7 = 0, count11 = 0, count13 = 0, count17 = 0, count19 =0;
	int numOfDivisors = 1;
	for(int n = 2; n<153000; n++) {
		long long int num = n*(n+1)/2;
		if(isPrime(num))
			continue;
		while(num % 2 == 0) {
			count2++;
			num = num/2;
		}
		if(count2 > 0)
			numOfDivisors *= (count2+1);
		while(num % 3 == 0) {
			count3++;
			num = num/3;
		}
		if(count3 > 0)
			numOfDivisors *= (count3+1);
		while(num % 5 == 0) {
			count5++;
			num = num/5;
		}
		if(count5 > 0)
			numOfDivisors *= (count5+1);
		while(num % 7 == 0) {
			count7++;
			num = num/7;
		}
		if(count7 > 0)
			numOfDivisors *= (count7+1);
		while(num % 11 == 0) {
			count11++;
			num = num/11;
		}
		if(count11 > 0)
			numOfDivisors *= (count11+1);
		
		while(num % 13 == 0) {
			count13++;
			num = num/13;
		}
		if(count13 > 0)
			numOfDivisors *= (count13+1);
		
		while(num % 17 == 0) {
			count17++;
			num = num/17;
		}
		if(count17 > 0)
			numOfDivisors *= (count17+1);
		
		while(num % 19 == 0) {
			count19++;
			num = num/19;
		}
		if(count19 > 0)
			numOfDivisors *= (count19+1);
		if(numOfDivisors > 500) {
			long long int trian = n*(n+1)/2;
			cout << trian << endl;
			cout << n << endl;
			break;
		}
		numOfDivisors = 1;
		count2 = 0;
		count3 = 0;
		count5 = 0;
		count7 = 0;
		count11 = 0;
		count13 = 0;
		count17 = 0;
		count19 = 0;
	}
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
