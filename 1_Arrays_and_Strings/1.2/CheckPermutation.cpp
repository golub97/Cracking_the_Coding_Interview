/*
Check Permutation: Given two strings, write a method to decide if one is a permutation of the
other.
*/
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool check_permutation(string &s1, string &s2)
{
    if(s1.length() != s2.length())
        return false;
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
            
    return s1.compare(s2) == 0;
}

int main()
{
    string s[] = {"nikola", "alokin"};
    string m[] = {"stevan", "stefan"};
    string q[] = {"qwerty", "qwerty"};
    
    cout << check_permutation(s[0], s[1]) << endl;
    cout << check_permutation(m[0], m[1]) << endl;
    cout << check_permutation(q[0], q[1]) << endl;
    
    return 0;
}
