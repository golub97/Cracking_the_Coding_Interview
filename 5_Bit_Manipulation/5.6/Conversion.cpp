//Conversion: Write a function to determine the number of bits you would need to flip to convert integer A to integer B.
//EXAMPLE
//Input: 29 (or: 11101), 15 (or: 01111)
//Output: 2 
#include <iostream>
using namespace std;

int bitSwapRequired(int a, int b)
{
    int count = 0;
    for(int c = a ^ b; c != 0; c = c & (c-1))
        count++;
        
    return count;
}

int main()
{
    int a = 29;
    int b = 15;
    
    int result = bitSwapRequired(a, b);
    
    cout << result;

    return 0;
}
