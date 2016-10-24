/*
 * Solution to Project Euler problem 23
 * by IlhanSeven
 
 * https://github.com/IlhanSeven/projectEuler
 * 
 * PROBLEM: Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */

/* ALGORITHM: -

Output: 4179871

real	0m0.124s
user	0m0.117s
sys	0m0.003s

on MacBook Pro 2015 i5
*/

#include <iostream>
#include <vector>

using namespace std;

int sum_of_divisors(int n){
  int prod=1;
  for(int k=2;k*k<=n;++k){
    int p=1;
    while(n%k==0){
      p=p*k+1;
      n/=k;
    }
    prod*=p;
  }
  if(n>1)
    prod*=1+n;
  return prod;
  
}

int main(){
	
	vector<int> abundant;
  
	for(int i=2;i<=28123;++i)
		if(sum_of_divisors(i)>2*i)
			abundant.push_back(i);
  
	bool sum_of_abundants[28123*2+1]={false};
  
	for(int i=0;i<abundant.size();++i)
		for(int j=0;j<=i;++j)
			sum_of_abundants[abundant[i]+abundant[j]]=true;
  
	int sum=0;
  
	for(int i=1;i<30000;++i)
		if(!sum_of_abundants[i])
			sum+=i;
  
	cout << sum << endl;

	return 0;
}



