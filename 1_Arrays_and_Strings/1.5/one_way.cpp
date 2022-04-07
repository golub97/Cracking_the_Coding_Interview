//One Away: There are three types of edits that can be performed on strings: insert a character,
//remove a character, or replace a character. Given two strings, write a function to check if they are
//one edit (or zero edits) away

#include <iostream>
#include <cmath>
using namespace std;

bool oneEditAway(string s1, string s2)
{
    if(abs((int)(s1.length() - s2.length())) > 1)
        return false;
    
    /* Get shorter and longer string.*/    
    string first  = (s1.length() < s2.length()) ? s1:s2; 
    string second = (s1.length() < s2.length()) ? s2:s1; 
    
    int index1 = 0;
    int index2 = 0;
    bool flag = false;
    
    while((index1 < first.length()) && (index2 < second.length()))
    {
        if(first[index1] != second[index2])
        {
            if(flag) return false;

            flag = true;
            
            if (first.length() == second.length()) index1++;  //On replace, move shorter pointer
        }
        else
        {
            index1++;  //If matching, move shorter pointer 
        }
        index2++;     // Always move pointer for longer string
    }
    
    return true;
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
