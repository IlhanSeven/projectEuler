/*
 * Solution to Project Euler problem 22
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: What is the total of all the name scores in the file?
 */

/* ALGORITHM: -

Output: 871198282

real	0m0.015s
user	0m0.011s
sys	0m0.003s

on MacBook Pro 2015 i5
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "math.h"

using namespace std;

int returnNumberEquivalent(char input);

int main() {

	ifstream iFile("p022_names.txt");
	if(!iFile) {
		cerr << "Can't find the file!\n";
		exit(EXIT_FAILURE);
	}

	string myArray[6000] = {};
	int index = 0;
	string line = "";
	getline(iFile, line);
	istringstream ss(line);
	string token;

	while(getline(ss, token, ',')) {
    	myArray[index] = token;
    	index ++;
	}
	sort(myArray, myArray+5163);
	int sum= 0;
	
	for (int i=0; i<5163; i++) {
		myArray[i] = myArray[i].substr(1, myArray[i].size()-2);
		int tempSum = 0;
		for(int j=0; j<myArray[i].size(); j++) {
			tempSum += returnNumberEquivalent(myArray[i].at(j));
		}
		sum += tempSum * (i+1);
	}
	cout << sum << endl;
	return 0;
}

int returnNumberEquivalent(char input) {
	if(input == 'A')
		return 1;
	if(input == 'B')
		return 2;
	if(input == 'C')
		return 3;
	if(input == 'D')
		return 4;
	if(input == 'E')
		return 5;
	if(input == 'F')
		return 6;
	if(input == 'G')
		return 7;
	if(input == 'H')
		return 8;
	if(input == 'I')
		return 9;
	if(input == 'J')
		return 10;
	if(input == 'K')
		return 11;
	if(input == 'L')
		return 12;
	if(input == 'M')
		return 13;
	if(input == 'N')
		return 14;
	if(input == 'O')
		return 15;
	if(input == 'P')
		return 16;
	if(input == 'Q')
		return 17;
	if(input == 'R')
		return 18;
	if(input == 'S')
		return 19;
	if(input == 'T')
		return 20;
	if(input == 'U')
		return 21;
	if(input == 'V')
		return 22;
	if(input == 'W')
		return 23;
	if(input == 'X')
		return 24;
	if(input == 'Y')
		return 25;
	if(input == 'Z')
		return 26;
	return 0;
}


