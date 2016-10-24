/*
 * Solution to Project Euler problem 17
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 */

/* ALGORITHM: -

Output: 21124

real	0m0.004s
user	0m0.001s
sys		0m0.002s

on MacBook Pro 2015 i5
*/

#include <iostream>
#include <string>

using namespace std;

string checkOne(int n) {
		if(n == 1)
			return "one";
		if(n == 2)
			return "two";
		if(n == 3)
			return "three";
		if(n == 4)
			return "four";
		if(n == 5)
			return "five";
		if(n == 6)
			return "six";
		if(n == 7)
			return "seven";
		if(n == 8)
			return "eight";
		if(n == 9)
			return "nine";
		return 0;
}

string checkTwo(int n) {

		if(n == 2)
			return "twenty";
		if(n == 3)
			return "thirty";
		if(n == 4)
			return "forty";
		if(n == 5)
			return "fifty";
		if(n == 6)
			return "sixty";
		if(n == 7)
			return "seventy";
		if(n == 8)
			return "eighty";
		if(n == 9)
			return "ninety";
		return 0;
}

string checkTeens(int n) {
		if(n == 10)
			return "ten";
		if(n == 11)
			return "eleven";
		if(n == 12)
			return "twelve";
		if(n == 13)
			return "thirteen";
		if(n == 14)
			return "fourteen";
		if(n == 15)
			return "fifteen";
		if(n == 16)
			return "sixteen";
		if(n == 17)
			return "seventeen";
		if(n == 18)
			return "eighteen";
		if(n == 19)
			return "nineteen";
		return 0;
}

string convertToString(int n) {
	
	int firstDigit = n%10;
	int secondDigit = ((n-firstDigit)/10)%10;
	int thirdDigit = (n-10*secondDigit-firstDigit)/100;
	
	string myOutputString = "";
	
	if(thirdDigit > 0) {
		myOutputString.append(checkOne(thirdDigit)).append("hundred");
		if(secondDigit != 0 || firstDigit != 0)
			myOutputString.append("and");
	}
	if(secondDigit > 0 && secondDigit < 2) {
		int secondPart = n%100;
		myOutputString.append(checkTeens(secondPart));
		return myOutputString;
	}
	if(secondDigit >=2) {
		myOutputString.append(checkTwo(secondDigit));
	}
	if(firstDigit > 0) {
		myOutputString.append(checkOne(firstDigit));
	}

	return myOutputString;
}

int main() {
	
	string myString = "";
	
	for(int i=1; i<1000; i++) {
		myString.append(convertToString(i));
	}
	myString.append("onethousand");
	
	cout << myString.length() << endl;
	return 0;
}
