/*
 * Solution to Project Euler problem 15
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * Problem: Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, 
 * there are exactly 6 routes to the bottom right corner. How many such routes are there through a 20×20 grid
 */

/* ALGORITHM:
A short combinatorial solution which calculates the combination formula with (40 20).

Output: 137846528820

real	0m0.005s
user	0m0.001s
sys		0m0.003s

on MacBook Pro 2015 i5
*/

#include <iostream>


int main() {
	
	long long int result = 1;
	for(int i=1; i<=20; i++) {
		result = result * (20+i)/i;
	}
	std::cout << result << std::endl;
	return 0;
}
