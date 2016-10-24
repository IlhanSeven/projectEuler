/*
 * Solution to Project Euler problem 14
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * Problem: Longest Collatz Sequence. Which starting number, under one million, produces the longest chain?
 */

/* ALGORITHM:
Brute force

Output: 837799

real	0m2.884s
user	0m2.873s
sys		0m0.006s

on MacBook Pro 2015 i5
*/

#include <iostream>

using namespace std;

int main() {

	int count = 0, tempCount = 1;
	int result;
	for(int i=1; i<1000000; i++) {
		long long int n = i;
		while(n>1) {
			if(n%2 == 0) {
				n = n/2;
				tempCount++;
			} else {
				n = 3*n + 1;
				tempCount++;
			}
		}
		if(tempCount > count) {
			count = tempCount;
			result = i;
		}
		tempCount = 1;
	}
	cout << count << " - " << result << endl;
	return 0;
}
