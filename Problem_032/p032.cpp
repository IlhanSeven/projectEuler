/*
 * Solution to Project Euler problem 32 - Pandigital products
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
 */

/* ALGORITHM: Below code is easy to understand.

Output:   45228

real    0m0.446s
user    0m0.434s
sys 0m0.005s

on MacBook Pro 2015 i5
*/

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;


bool areDigitsDistinct(int n) {
    vector<int> digits;
    while (n>0) {
        int x = n%10;
        if(x == 0)
            return false;
        digits.push_back(x);
        n /= 10;
    }
    for(int i=0; i<digits.size(); i++) {
        for(int j=i+1; j<digits.size(); j++) {
            if(digits.at(i) == digits.at(j))
                return false;
        }
    }
    return true;
}

int main() {
    
    int start_s=clock();
    
    vector<int> v;
    int sum = 0;
    
    for(int i = 2; i<99; i++) {
        if(areDigitsDistinct(i)) {
            for(int j = 123; j<4987; j++) {
                if(areDigitsDistinct(j)) {
                    int prod = i*j;
                    if(areDigitsDistinct(prod)) {
                        string finalSeq = to_string(prod) + to_string(i) + to_string(j);
                        if(finalSeq.size() != 9) {
                            continue;
                        } else {
                            int n = stoi(finalSeq);
                            if(areDigitsDistinct(n)) {
                                cout << prod << "\t" << i << "\t" << j << endl;
                                if(!(find(v.begin(), v.end(), prod) != v.end())) {
                                    v.push_back(prod);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    for(int i=0; i<v.size(); i++) {
        sum += v.at(i);
    }
    
    cout << sum << endl;
    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}