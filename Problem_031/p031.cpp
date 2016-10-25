/*
 * Solution to Project Euler problem 31 - Coin sums
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: How many different ways can £2 be made using any number of coins?
 */

/* ALGORITHM: Recursive way.

Output:   73682

real	0m0.007s
user	0m0.003s
sys	0m0.002s

on MacBook Pro 2015 i5
*/

#include <iostream>
using namespace std;

int coins[8] = {200, 100, 50, 20, 10, 5,2,1};

int findWays(int amount, int noOfNotUsedCoins)
{
    int sum = 0;
    if(noOfNotUsedCoins == 7) return 1;
    for(int i = noOfNotUsedCoins; i<8;i++)
    {
        if (amount-coins[i] == 0) sum+=1;
        if (amount-coins[i] > 0) sum+=findWays(amount-coins[i], i);
    }
    return sum;     
}

int main()
{
    cout << findWays(200, 0) << endl;
    return 0;
}