/*
 * Solution to Project Euler problem 10
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * Problem: Find the sum of all the primes below two million.
 */

/* ALGORITHM:
We will use the powerful isPrime function.

Output: 142913828922

real    0m0.219s
user    0m0.207s
sys     0m0.005s

*/

#include <iostream>
#include "math.h"

bool isPrime(int n);

int main() {
    long int sum = 0;
    for(int i =1; i<2000000; i++) {
        if (isPrime(i)){
            sum += i;
        }
    }
    std::cout << sum << std::endl;
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
