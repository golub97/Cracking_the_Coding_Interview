//One Away: There are three types of edits that can be performed on strings: insert a character,
//remove a character, or replace a character. Given two strings, write a function to check if they are
//one edit (or zero edits) away

#include <iostream>

using namespace std;

bool oneEditReplace(string s1, string s2)
{
    bool flag = false; //flag for exactly one change
    
    for(int i = 0; i < s1.length(); ++i)
    {
        if(s1[i] != s2[i])
        {
            if(flag)
            {
                return false;
            }
            else
            {
                flag = true;
            }
        }
    }  
    
    return true;
}

bool oneEditinsert(string s1, string s2)
{
    int index1 = 0;
    int index2 = 0;
    
    while((index1 < s1.length()) && (index2 < s2.length()))
    {
        if(s1[index1] != s2[index2])
        {
            if(index1 != index2)
            {
                return false;
            }
            index1++;
            
        }
        else
        {
            index1++;
            index2++;
        }
    }
    
    return true;
}

bool oneEditAway(string s1, string s2)
{
    if(s1.length() == s2.length())
        return oneEditReplace(s1, s2);
    else if(s1.length() + 1 == s2.length())
        return oneEditinsert(s1, s2);
    else if(s1.length() - 1 == s2.length())
        return oneEditinsert(s1, s2);
    else
        return false;
}

int main()
{
    string s1 = "pale";
    string s2 = "ple";
    
    cout << oneEditAway(s1, s2) << endl;
    
    string s3 = "pales";
    
    cout << oneEditAway(s3, s1) << endl;
    
    string s4 = "bale";
    
    cout << oneEditAway(s1, s4) << endl;
    
    string s5 = "bake";
    
    cout << oneEditAway(s1, s5) << endl;
    
    string s6 = "Nikolaa";
    string s7 = "Nikola";
    
    cout << oneEditAway(s6, s7) << endl;

    return 0;
}
