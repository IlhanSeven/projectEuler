/*
 * Solution to Project Euler problem 4
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * Problem: Find the largest palindrome made from the product of two 3-digit numbers?
 */

/* ALGORITHM:
isPalindrome() function to see if a number is palindrome.
Iterate down from 999 to find the biggest palindrome.

Output: 906609

real    0m0.024s
user    0m0.018s
sys     0m0.003s
*/

#include <iostream>
#include "math.h"

bool isPalindrome(int n);

int main() {
    
    int biggestPal = 0;
    for(int i=999; i>=100; i--) {
        for(int j=999; j>=100; j--) {
            if(isPalindrome(i*j)) {
                int temp = i*j;
                if(temp>biggestPal)
                    biggestPal = temp;
            }
        }
    }
    
    std::cout << biggestPal << std::endl;
    
    return 0;
}

bool isPalindrome(int n) {
    int k = n/1000;
    int m = n%1000;
    int newM = (m%10)*100 + (m%100 - m%10)+ m/100;
    if(k == newM) {
        return true;
    }
    return false;
}
