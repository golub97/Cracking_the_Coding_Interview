//String Rotation: Assume you have a method isSubstring which checks if one word is a substring 
//of another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one 
//call to isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat"). 

#include <iostream>

using namespace std;

bool isRotation(string s1, string s2)
{
    int len = s1.length();
    /* Check that s1 and s2 are equal length and not empty*/ 
    if (len == s2.length() && len > 0) 
    {
        /* Concatenate s1 and s1 within new buffer */
        string s1s1 = s1 + s1;
        return issubstring(s1s1, s2); 
    }
    return false;
}

int main()
{
    cout<<"Hello World";

    return 0;
}
