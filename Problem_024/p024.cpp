/*
 * Solution to Project Euler problem 24
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

/* ALGORITHM: Explained below

Output: 2783915460

real	0m13.097s
user	0m6.089s
sys	0m3.006s

on MacBook Pro 2015 i5
*/

#include <iostream>
#include <string>
#include <vector>


using namespace std;

vector<string> v;

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r)
{
   int i;
   if (l == r) {
     printf("%s\n", a);
     //long long int x = stoi(a);
     v.push_back(a);
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}
 
/* Driver program to test above functions */
int main()
{
    char str[] = "0123456789";
    int n = strlen(str);
    permute(str, 0, n-1);

    sort(v.begin(), v.end());
    cout << endl;
    cout << v.at(999999);
    return 0;
}