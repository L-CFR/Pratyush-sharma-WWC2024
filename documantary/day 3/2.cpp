/*Q2 . Elimination Game
You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr Starting
from left to right, remove the first number and every other number afterward until you reach the end of the list.Repeat the previous step again,
but this time from right to left, remove the rightmost number and every other number from the remaining numbers.Keep repeating the steps again,
alternating left to right and right to left, until a single number remains.
*/
#include <iostream>
using namespace std;

int lastRemaining(int n) {
    int head = 1;      
    int step = 1;      
    int remaining = n; 
    bool left = true;  
    
    while (remaining > 1) {
        if (left || remaining % 2 == 1) {
            head += step; 
        }
        step *= 2;        
        remaining /= 2;   
        left = !left;     
    }
    
    return head; // The last remaining number
}

int main() {
    int n = 9;
    cout << "Last remaining number: " << lastRemaining(n) << endl;
    return 0;
}
