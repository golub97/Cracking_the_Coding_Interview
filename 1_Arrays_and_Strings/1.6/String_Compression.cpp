//String Compression: Implement a method to perform basic string compression using the counts
//of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
//"compressed" string would not become smaller than the original string, your method should return
//the original string. You can assume the string has only uppercase and lowercase letters (a - z). 

#include <iostream>
#include <string>

using namespace std;

string compressBad(string s)
{
    string compressed_string = "";
    int countConsecutive = 0;
    
    for(int i = 0; i < s.size(); ++i)
    {
        countConsecutive++;
        
        if((s[i] != s[i+1]) || ((i + 1) >= s.length()))
        {
            compressed_string += s[i];
            compressed_string += to_string(countConsecutive);
            countConsecutive = 0;
        }
    }
    
    return s.length() < compressed_string.length() ? s:compressed_string;
}

int main()
{
    string s1 = "aabcccccaaa";
    
    cout << compressBad(s1) << endl;
    
    string s2 = "abcdef";
    
    cout << compressBad(s2) << endl;
    
    string s3 = "aaabbbcccdddeeefff";
    
    cout << compressBad(s3) << endl;

    return 0;
}
