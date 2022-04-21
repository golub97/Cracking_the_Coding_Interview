//Insertion: You are given two 32-bit numbers, N and M, and two bit positions, i and j. 
//Write a method to insert M into N such that M starts at bit j and ends at bit i. 
//You can assume that the bits j through i have enough space to fit all of M. 
//That is, if M = 10011, you can assume that there are at least 5 bits between j and i. 
//You would not, for example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2.
//EXAMPLE
//Input: N = 10000000000, M = 10011, i = 2, j = 6 
//Output: N = 10001001100
#include <iostream>
using namespace std;

int updateBits(int n, int m, int i, int j)
{
    //Create a mask to clear bits i through j in n. EXAMPLE: i = 2, j = 4. 
    //Result should be 11100011. 
    //For simplicity, we'll use just 8 bits for the example. 
    
    int allOnes = ~0; //will equal sequence of all ls
    
    //ls before position j, then 0s. left = 11100000
    int left = allOnes << (j + 1); 
    
    //1's after position i. right = 00000011
    int right = (1 << i) - 1;
    
    int mask = left | right;
    
    /* Clear bits j through i then put min there */
    int n_cleared = n & mask; //Clear bits j through i.
    int m_shifted = m << i; // Move m into correct position. 
    
    return n_cleared | m_shifted;
}

void bin_print(long n)
{
    long i;
    cout << "0";
    for (i = 1 << 30; i > 0; i /= 2)
    {
        if((n & i) != 0)
            cout << "1";
        else
            cout << "0";
    }
    
    cout << endl;
}

int main()
{
    int n = 0x400; //N = 10000000000
    int m = 0x013;  //M  = 10011
    int i = 2;
    int j = 6;
    int result = 0;
    
    bin_print(n);
    bin_print(m);

    result = updateBits(n, m, i, j);
    
    bin_print(result);

    return 0;
}
