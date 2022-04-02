/*
1.1 Is Unique: Implement an algorithm to determine if a string has all unique characters.
What if you cannot use additional data structures?
*/

#include <iostream>
using namespace std;

bool unique_characters(string s)
{
    int checker = 0;
    int val = 0;
    for(int i = 0; i < s.length(); ++i)
    {
        val = s[i] - 'a';
        if((checker & (1 << val)) > 0)
            return false;
        checker |= (1 << val);
    }
    return true;
}

int main()
{
    string array[] = {"nikola", "nikolina", "marijan", "marijana", "dejan", "dejana"};
    
    for(int i = 0; i < sizeof(array)/sizeof(string); ++i)
    {
        if(true == unique_characters(array[i]))
            cout << array[i] << " has unique characters" << endl;
        else
            cout << array[i] << " doesn't have unique characters" << endl;
    }
    return 0;
}
