/*
 * Solution to Project Euler problem 36 - Double-base palindromes
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
 * Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
 * (Please note that the palindromic number, in either base, may not include leading zeros.)
 */

/* ALGORITHM: First, continuously dividing by the base we find the no of digits. The purpose of finding the digits is
to find the biggest power of base in order for calcaulation check of isPlalindrome.

We, then calculate the new number by multiplying the least siginificant digit by the (digit-1)th power of base and so on.
After comparion of new number and input we find out if number is palindrome. 

Btw, the numbers are clearly odd, so that further reduces the execution time.

Output:   872187

real	0m0.127s
user	0m0.121s
sys	0m0.002s

on MacBook Pro 2015 i5
*/

#include <iostream>
#include <cmath>

using namespace std;

int noOfDigits(int n, int base) {
	int count = 0;
	while(n>0) {
		count += 1;
		n /= base;
	}
	return count;
}

bool isPalindrome(int n, int base) {
	int digits = noOfDigits(n, base);
	int newNum = 0;
	int input = n;
	while(n>0) {
		newNum += (n%base) * pow(base, (digits-1));
		n /= base;
		digits -= 1;
	}
	if(newNum == input)
		return true;
	return false;
}

int main() {

	int sum = 0;
	for(int i=1; i<1000000; i+=2) {
		if(isPalindrome(i, 10))
			if(isPalindrome(i, 2))
				sum += i;
	}

	cout << sum << endl;

    return 0;
}