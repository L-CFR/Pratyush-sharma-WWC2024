/*Q5 Minimun  non zero product of an Array Elements
You are given a positive integer p. Consider an array nums (1-indexed) that consists of the integers in the inclusive range [1, 2p - 1] in their
 binary representations. You are allowed to do the following operation any number of times: Choose two elements x and y from nums.
Choose a bit in x and swap it with its corresponding bit in y. Corresponding bit refers to the bit that is in the same position in the other 
integer.For example, if x = 1101 and y = 0011, after swapping the 2nd bit from the right, we have x = 1111 and y = 0001.Find the minimum non-zero
product of nums after performing the above operation any number of times. Return this product modulo 109 + 7.
*/
#include <iostream>
using namespace std;

// Function to perform modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2; 
    }
    return result;
}

int minNonZeroProduct(int p) {
    const long long MOD = 1e9 + 7;
    long long maxVal = (1LL << p) - 1; 
    long long secondMaxVal = maxVal - 1; 
    long long count = (1LL << (p - 1)) - 1;
    
    // Compute result using modular arithmetic
    long long product = modExp(secondMaxVal, count, MOD);
    product = (product * maxVal) % MOD;
    
    return product;
}

int main() {
    int p = 3;
    cout << "Minimum Non-Zero Product: " << minNonZeroProduct(p) << endl;
    return 0;
}
