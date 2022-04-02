/*
1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters.
What if you cannot use additional data structures?
*/

#include <iostream>
using namespace std;
#define ASize 128

bool unique_characters(string s)
{
    bool* flags = new bool[ASize];
    for(int i = 0; i < ASize; ++i)
        flags[i] = false;
        
    for(int i = 0; i < s.length(); ++i)
    {
        if(true == flags[s[i]])
            return false;
        flags[s[i]] = true;
    }
    return true;
}

int main()
{
    string array[] = {"Nikola", "Nikolina", "Marijan", "Marijana", "Dejan", "Dejana"};
    
    for(int i = 0; i < sizeof(array)/sizeof(string); ++i)
    {
        if(true == unique_characters(array[i]))
            cout << array[i] << " has unique characters" << endl;
        else
            cout << array[i] << " doesn't have unique characters" << endl;
    }
    return 0;
}
