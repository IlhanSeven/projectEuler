/*
 * Solution to Project Euler problem 19
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */

/* ALGORITHM: Be careful about leap years rule. A century should be divisible by 400 to be a leap year.

Output: 171

real	0m0.007s
user	0m0.003s
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
	
	// 1 Jan 1901 is Tuesday & to 31 Dec 2000
	
	string myArray[100][366] = {};
	
	myArray[0][0] = "Tuesday";
	myArray[0][1] = "Wednesday";
	myArray[0][2] = "Thursday";
	myArray[0][3] = "Friday";
	myArray[0][4] = "Saturday";
	myArray[0][5] = "Sunday";
	myArray[0][6] = "Monday";
	for (int i = 0; i < 358; i++)
	{
		myArray[0][i+7] = myArray[0][i];
	}

	for(int i=1; i<100; i++) {
		if((i+1) % 4 == 0) {
			myArray[i][0] = myArray[i-1][358];
			myArray[i][1] = myArray[i-1][359];
			myArray[i][2] = myArray[i-1][360];
			myArray[i][3] = myArray[i-1][361];
			myArray[i][4] = myArray[i-1][362];
			myArray[i][5] = myArray[i-1][363];
			myArray[i][6] = myArray[i-1][364];

			for(int j=0; j<359; j++) {
				myArray[i][j+7] = myArray[i][j];
			}
		} else {
			if(myArray[i-1][365] != "") {
				myArray[i][0] = myArray[i-1][359];
				myArray[i][1] = myArray[i-1][360];
				myArray[i][2] = myArray[i-1][361];
				myArray[i][3] = myArray[i-1][362];
				myArray[i][4] = myArray[i-1][363];
				myArray[i][5] = myArray[i-1][364];
				myArray[i][6] = myArray[i-1][365];
				for(int j=0; j<358; j++) {
					myArray[i][j+7] = myArray[i][j];
				}
			} else {
				myArray[i][0] = myArray[i-1][358];
				myArray[i][1] = myArray[i-1][359];
				myArray[i][2] = myArray[i-1][360];
				myArray[i][3] = myArray[i-1][361];
				myArray[i][4] = myArray[i-1][362];
				myArray[i][5] = myArray[i-1][363];
				myArray[i][6] = myArray[i-1][364];

				for(int j=0; j<358; j++) {
					myArray[i][j+7] = myArray[i][j];
				}
			}
		}
	}

	int countSundays = 0;

	for(int i=0; i<100; i++) {
		if((i+1) % 4 == 0) {
			if(myArray[i][0] == "Sunday")
				countSundays++;
			if(myArray[i][31] == "Sunday")
				countSundays++;
			if(myArray[i][60] == "Sunday")
				countSundays++;
			if(myArray[i][91] == "Sunday")
				countSundays++;
			if(myArray[i][121] == "Sunday")
				countSundays++;
			if(myArray[i][152] == "Sunday")
				countSundays++;
			if(myArray[i][182] == "Sunday")
				countSundays++;
			if(myArray[i][211] == "Sunday")
				countSundays++;
			if(myArray[i][242] == "Sunday")
				countSundays++;
			if(myArray[i][272] == "Sunday")
				countSundays++;
			if(myArray[i][303] == "Sunday")
				countSundays++;
			if(myArray[i][333] == "Sunday")
				countSundays++;
		} else {
			if(myArray[i][0] == "Sunday")
				countSundays++;
			if(myArray[i][31] == "Sunday")
				countSundays++;
			if(myArray[i][59] == "Sunday")
				countSundays++;
			if(myArray[i][90] == "Sunday")
				countSundays++;
			if(myArray[i][120] == "Sunday")
				countSundays++;
			if(myArray[i][151] == "Sunday")
				countSundays++;
			if(myArray[i][181] == "Sunday")
				countSundays++;
			if(myArray[i][210] == "Sunday")
				countSundays++;
			if(myArray[i][241] == "Sunday")
				countSundays++;
			if(myArray[i][271] == "Sunday")
				countSundays++;
			if(myArray[i][302] == "Sunday")
				countSundays++;
			if(myArray[i][332] == "Sunday")
				countSundays++;
		}
	}
	cout << countSundays << endl;
	
	return 0;
}
