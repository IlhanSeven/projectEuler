/*
 * Solution to Project Euler problem 7
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * Problem: What is the 10 001st prime number?
 */

/* ALGORITHM:

After 2 and 3, we know that all primes are in the form of either 6n-1 or 6n+1

Output: 104743

real	0m0.010s
user	0m0.006s
sys		0m0.003s

*/

#include <iostream>
#include "math.h"

bool isPrime(int n);

int main() {

    long int primeNum10001;
    int index = 2; // Counted primes 2 and 3
    int n = 1;

    while(index<10001) {

    	if(isPrime(n*6-1)) {
    		index++;
    	} 
    	if(isPrime(n*6+1)) {
    		index++;
    	}
    	n++;
    }
    if(isPrime((n-1)*6+1))
    	std::cout << (n-1)*6+1 << std::endl;
    else
    	std::cout << (n-1)*6-1 << std::endl;
    
    return 0;
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
