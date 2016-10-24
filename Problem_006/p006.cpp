/*
 * Solution to Project Euler problem 6
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * Problem: Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.?
 */

/* ALGORITHM:

Using the n*(n+1)/2 to calculate sum. The other is obvious.

Output: 25164150

real    0m0.006s
user    0m0.002s
sys     0m0.004s

*/

#include <iostream>
#include "math.h"

int main() {


    long int sumOfSquares = 0;
    long int squareOfSum = pow(50*101, 2);

    for(int i = 1; i<=100; i++) {
        sumOfSquares += i * i;
    }
    
    std::cout << squareOfSum - sumOfSquares << std::endl;
    
    return 0;
}
