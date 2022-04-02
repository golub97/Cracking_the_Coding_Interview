/*
Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. 
A palindrome is a word or phrase that is the same forwards and backwards. 
A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
EXAMPLE
Input: Tact Coa
Output: True (permutations: "taco cat", "atco eta", etc.)
*/

#include <iostream>

using namespace std;
#define ASCII 128

bool palindrome_permutation(string str)
{
    int countOdd = 0;
    int* p = new int[ASCII];
    
    for(int i = 0; i < ASCII; ++i)
        p[i] = 0;
    
    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i] != 32) //ignore space character
        {
            if(65 <= str[i] && str[i] <= 90) //convert big letters to small letters
                p[str[i]+32]++;
            else
                p[str[i]]++;
                
            if(1 == (p[i] % 2))
            {
                 countOdd++;
            }
            else
            {
                countOdd--;
            }
        }
    }
        
    return countOdd <= 1;
}

int main()
{
    string str = "Tact Coa";
    
    cout << palindrome_permutation(str) << endl;
    
    return 0;
}

