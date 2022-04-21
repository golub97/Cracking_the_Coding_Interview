//Debugger: Explain what the following code does: ((n & (n-1 )) == 0). 
#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cout << ((n & (n-1)) == 0) << endl;
    n = 1;
    cout << ((n & (n-1)) == 0) << endl;
    n = 2;
    cout << ((n & (n-1)) == 0) << endl;
    n = 4;
    cout << ((n & (n-1)) == 0) << endl;
    n = 8;
    cout << ((n & (n-1)) == 0) << endl;
    n = 16;
    cout << ((n & (n-1)) == 0) << endl;
    n = 32;
    cout << ((n & (n-1)) == 0) << endl;
    n = 33;
    cout << ((n & (n-1)) == 0) << endl;

    return 0;
}
