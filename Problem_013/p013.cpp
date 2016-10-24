/*
 * Solution to Project Euler problem 13
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * Problem: Work out the first ten digits of the sum of the given one-hundred 50-digit numbers.
 */

/* ALGORITHM:
An array mechanism was used to hold every digit. Full output can be obtained.

Output: 76576500

real    0m0.006s
user    0m0.001s
sys     0m0.003s

on MacBook Pro 2015 i5
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ifstream iFile("number.txt");
	if(!iFile) {
		cerr << "Can't find the file!\n";
		exit(EXIT_FAILURE);
	}
	int myArray[100][50];
	int row = 0;

	while(!iFile.eof()) {
		string line = "";
		try {
			getline(iFile, line);
			for(int col=0; col<50; col++) {
				myArray[row][col] = int(line.at(col)) - 48;
			}
		} catch(...) {
			continue;
		}
		row++;
	}
	
	vector<int> bigSum;
	int oneSum = 0;
	int toBeAdded = 0;
	
	for(int j=49; j>=0; j--) {
		for(int i=0; i<100; i++) {
			oneSum += myArray[i][j];
		}
		oneSum += toBeAdded;
		int remainder = oneSum % 10;
		toBeAdded = (oneSum-remainder)/10;
		bigSum.push_back(remainder);
		oneSum = 0;
	}
	bigSum.push_back(toBeAdded % 10);
	bigSum.push_back((toBeAdded - (toBeAdded%10))/10);
	
	for(int x=bigSum.size()-1; x>bigSum.size()-11; x--) {
		cout << bigSum.at(x);
	}
	cout << endl;
	return 0;
}
