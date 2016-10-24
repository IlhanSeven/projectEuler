/*
 * Solution to Project Euler problem 4
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * Problem: What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

/* ALGORITHM:
If we think reverse, it is the same as finding common multiple of all numbers from 1 to 20.
Only two primes have powers in the range to 20; 2 and 3 with 2^4 = 16 and 3^2 = 9.
So we need to multiply every prime and also multiply with 2^3 and 3 which is 24.

Output: 232792560

real    0m0.006s
user    0m0.001s
sys     0m0.003s

*/

#include <iostream>
#include "math.h"

bool isPrime(int n);

int main() {


    long int smallest = 1;

    for(int i =1; i<=20; i++) {
        if (isPrime(i))
        {
            smallest *= i;
        }
    }
    
    std::cout << smallest*24 << std::endl;
    
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
