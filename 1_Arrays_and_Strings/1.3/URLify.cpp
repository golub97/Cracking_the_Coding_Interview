#include <iostream>
using namespace std;

void replaceSpaces(string &str, int trueLength)
{
    int number_of_spaces = 0;
    int index = 0;

    for(int i = 0; i < trueLength; ++i)
        if(' ' == str[i])
            number_of_spaces++;
            
    index = trueLength + 2*number_of_spaces;
    
    for(int i = trueLength - 1; i >= 0; --i)
    {
        if(str[i] == ' ')
        {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index-=3;
        
        }
        else
        {
            str[index - 1] = str[i];
            --index;
        }
    }
}

int main()
{
    string s1 = "Mr John Smith    ";
    replaceSpaces(s1, 13);
    cout << s1;
    
    return 0;
}
