/*
 * Solution to Project Euler problem 20
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: Find the sum of the digits in the number 100!
 */

/* ALGORITHM: I really did calculate 100! for this. I just love doing it.

Output: 648

real	0m0.005s
user	0m0.002s
sys		0m0.003s

on MacBook Pro 2015 i5
*/

#include <iostream>

using namespace std;

int main() {
	
	int factorialArray[90][200] = {0};
	factorialArray[0][0] = 0;
	factorialArray[0][1] = 0;
	factorialArray[0][2] = 8;
	factorialArray[0][3] = 8;
	factorialArray[0][4] = 2;
	factorialArray[0][5] = 6;
	factorialArray[0][6] = 3;
	
	for(int i=11; i<100; i++) {
			int k = i%10;
			int y = (i-k)/10;
			int tempArray[1][200] = {0};
			int tempArray2[1][200] = {0};
			int toBeAdded = 0, toBeAdded2 = 0, toBeAdded3 = 0;
			
			for(int m=0; m<200; m++) {
				int z = k * factorialArray[i-11][m] + toBeAdded;
				int c = y * factorialArray[i-11][m] + toBeAdded2;
				
				if(z >= 10) {
					tempArray[0][m] = z%10;
					toBeAdded = (z - z%10)/10;
				} else {
					tempArray[0][m] = z;
					toBeAdded = 0;
				}
				
				if(c >= 10) {
					tempArray2[0][m+1] = c%10;
					toBeAdded2 = (c - c%10)/10;
				} else {
					tempArray2[0][m+1] = c;
					toBeAdded2 = 0;
				}
				
				int p = tempArray[0][m] + tempArray2[0][m] + toBeAdded3;
				if( p >= 10) {
					factorialArray[i-10][m] = p%10;
					toBeAdded3 = (p - p%10)/10;
				} else {
					factorialArray[i-10][m] = p;
					toBeAdded3 = 0;
				}
			}
	}
	
	int answer = 0;
	for(int j=199; j>=0; j--) {
		answer += factorialArray[89][j];
	}
	cout << answer << endl;

	return 0;
}

