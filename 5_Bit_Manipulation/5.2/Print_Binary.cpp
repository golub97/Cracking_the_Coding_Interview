//Binary to String: Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, 
//print the binary representation. 
//If the number cannot be represented accurately in binary with at most 32 characters, print"ERROR:' 
#include <iostream>
using namespace std;

string printBinary(double num) 
{
    if(num >= 1 || num <= 0)
        return "ERROR";
        
    string binary = "";
    binary.append("."); 
    while(num > 0)
    {
        /* Setting a limit on length: 32 characters */
        if (binary.length() >= 32) 
            return "ERROR";
        
        double r = num * 2;
        if(r >= 1)
        {
            binary.append("1");
            num = r - 1; 
        }
        else
        {
            binary.append("0");
            num = r;
        }
    }
    return binary;
}

int main()
{
    double number = 0.625;
    
    cout << printBinary(number);
    
    return 0;
}
