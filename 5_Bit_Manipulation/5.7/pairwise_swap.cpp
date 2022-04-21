//Pairwise Swap: Write a program to swap odd and even bits in an integer with as few instructions as possible 
//(e.g., bit O and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on). 
#include <iostream>
using namespace std;

int swapOddEvenBits(int x)
{
    return ((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1);
}

int main()
{
    int a = 0xAAAAAAAA;

    int result = swapOddEvenBits(a);
    
    printf("%X\n", result);
    
    a = 0x55555555;
    
    result = swapOddEvenBits(a);
    
    printf("%X", result);

    return 0;
}
