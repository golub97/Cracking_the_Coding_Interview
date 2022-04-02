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
    int bit_vector = 0;
    
    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i] != 32) //ignore space character
        {
            if(65 <= str[i] && str[i] <= 90)              //convert big letters to small letters
                bit_vector ^= 1 << (str[i] + 32 - 'a');   //toggle
            else
                bit_vector ^= 1 << (str[i] - 'a');        //toggle
        }
    }
    return bit_vector == 0 || ((bit_vector & (bit_vector - 1)) == 0); //check if we have exatcly number 0 or exatcly one bit set
}

int main()
{
    string str0 = "Tact Coa";
    string str1 = "Milovana voli ana";
    string str2 = "Udovica baci vodu";
    string str3 = "Vodu baci udovica";
    string str4 = "ovo ne bi trebalo";
    string str5 = "Ovo isto";
    
    cout << palindrome_permutation(str0) << endl;
    cout << palindrome_permutation(str1) << endl;
    cout << palindrome_permutation(str2) << endl;
    cout << palindrome_permutation(str3) << endl;
    cout << palindrome_permutation(str4) << endl;
    cout << palindrome_permutation(str5) << endl;
    
    return 0;
}
