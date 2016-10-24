/*
 * Solution to Project Euler problem 9
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * Problem: Problem 9: a+b+c=1000, a^2+b^2=c^2. Find a*b*c!
 */

/* ALGORITHM:

Nothing special. However this problem can be solved by hand. If you try a couple of famous Pythagorean triplets, you should
see that this problem follows 8 15 17 pattern. Which sums to 40 and that is evenly divisible by 1000.
Actually our numbers are 200, 375 and 425.

Output: 31875000

real    0m0.013s
user    0m0.007s
sys     0m0.003s

*/

#include <iostream>
#include <string>
#include "math.h"

using namespace std;

int main() {
    int a = 100, b = 100;
    while(b < 500) {
        while(a<b) {
            float c = sqrt(pow(a,2)+pow(b,2));
            if(a+b+c == 1000) {
                long int output = a*b*c;
                cout << output << endl;
            }
            a++;
        }
        a=100;
        b++;
    }
}
