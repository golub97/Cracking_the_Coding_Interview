/*
Check Permutation: Given two strings, write a method to decide if one is a permutation of the
other.
*/
#include <iostream>
#define ASCII 128

using namespace std;

bool check_permutation(string s1, string s2)
{
    if(s1.length() != s2.length())
        return false;
   
    int* p = new int[ASCII];
    
    for(int i = 0; i < ASCII; ++i)
        p[i] = 0;
    
    for(int i = 0; i < s1.length(); ++i)
        p[s1[i]]++;
    
    for(int i = 0; i < s2.length(); ++i)
        if(--p[s2[i]] < 0)
            return false;
            
    return true;
}

int main()
{
    string s[] = {"nikola", "alokin"};
    string m[] = {"stevan", "stefan"};
    string q[] = {"qwerty", "qwertyu"};
    
    cout << check_permutation(s[0], s[1]) << endl;
    cout << check_permutation(m[0], m[1]) << endl;
    cout << check_permutation(q[0], q[1]) << endl;
    
    return 0;
}
