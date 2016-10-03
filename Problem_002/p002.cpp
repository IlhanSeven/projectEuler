// Find the sum of even-valued Fibonacci numbers below 4 million
#include<iostream>

int main() {
    
    int sum = 0;
    int a = 1, b = 2;
    int c = a + b;
    
    while (c < 4000000) {
        if(c % 2 ==0) {
            sum += c;
        }
        
        a = b;
        b = c;
        c = a + b;
    }
    
    std::cout << sum+2 << std::endl;
    
    return 0;
}
