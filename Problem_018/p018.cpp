/*
 * Solution to Project Euler problem 18
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * Find the maximum total from top to bottom of the triangle given.
 */

/* ALGORITHM: Once you find the logic, this problem becomes very easy.
You should start from bottom and compare two adjacent numbers. And then add the bigger number to upper row.
By this way you will eliminate rows one by one until you reach to the top. Question 67 has the same logic.

Output: 1074

real	0m0.005s
user	0m0.001s
sys		0m0.003s

on MacBook Pro 2015 i5
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "math.h"

using namespace std;

int main() {
	ifstream iFile("p018_triangle.txt");
	if(!iFile) {
		cerr << "Can't find the file!\n";
		exit(EXIT_FAILURE);
	}
	int myArray[15][15] = {0};
	int row = 0;
	int col = 0;

	while(!iFile.eof()) {
		string line = "";
		try {
			getline(iFile, line);
			string buf;
			stringstream ss(line);
			while( ss >> buf){
				myArray[row][col] = stoi(buf);
				col++;
			}
		} catch(...) {
			continue;
		}
		col = 0;
		row++;
	}
	for (int i = 14; i > 0; i--)
	{
		for(int j=0; j<15; j++) {
			myArray[i-1][j] += max(myArray[i][j], myArray[i][j+1]);
		}
	}
	cout << myArray[0][0];
	return 0;
}
