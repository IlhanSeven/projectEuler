/*
 * Solution to Project Euler problem 16
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * Problem: What is the sum of the digits of the number 2^1000?
 */

/* ALGORITHM:
Using an array for digits the real sum is indeed calcualted.

Output: 1366

real	0m0.011s
user	0m0.005s
sys		0m0.005s

on MacBook Pro 2015 i5
*/

#include <iostream>

using namespace std;

int main() {

	int myArray[1000][400] = {0};
	myArray[0][0] = 2;

	int check = 0;
	int toBeAdded = 0;

	for(int i=1; i<1000; i++) {
		for(int j=0; j<400; j++) {
			check = myArray[i-1][j]*2 + toBeAdded;

			if(check >=10) {
				myArray[i][j] = check % 10;
				toBeAdded = 1;
			} else {
				myArray[i][j] = check;
				toBeAdded = 0;
			}
		}
		toBeAdded = 0;
	}

	int sum =0;
	for(int m=0; m<400; m++) {
		sum += myArray[999][m];
	}
	cout << sum;
	return 0;
}
