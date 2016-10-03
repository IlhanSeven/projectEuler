/*
 * Solution to Project Euler problem 3
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * Problem: What is the largest prime factor of the number 600851475143 ?
 */

#include <iostream>
#include "math.h"

bool isPrime(int n);

int main() {
    
    int largestPrime = 1;
    long int input = 600851475143;
    int cap = floor(sqrt(600851475143));
    for (int i = 1; i < cap; i++) {
        if (isPrime(i)) {
            if (input % i == 0) {
                largestPrime = i;
            }
        }
    }
    
    std::cout << largestPrime << std::endl;
    
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
