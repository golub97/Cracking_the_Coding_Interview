/* C++ program to implement basic stack operations */
#include <bits/stdc++.h>
using namespace std;
 
#define MAX 1000
 
class Stack {
    int top;
public:
    int a[MAX]; // Maximum size of Stack
 
    Stack() { top = -1; }
    bool push(int x);
    int pop(void);
    int peek(void); //top
    bool isEmpty(void);
};

bool Stack::push(int x)
{
    if(top >= (MAX - 1))
    {   
        cout << "Stackoveflow occured\n";
        return false;
    }   
    else
    {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop(void)
{
    if(top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        return a[--top];
    }
}

int Stack::peek(void)
{
    if(top < 0)
    {
        cout << "Stack is empty";
        return 0;
    }
    else
    {
        return a[top];
    }
}

bool Stack::isEmpty(void)
{
    return top < 0;
}


int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " Popped from stack\n";
    //print all elements in stack :
    cout <<"Elements present in stack : ";
    while(!s.isEmpty())
    {
        // print top element in stack
        cout << s.peek() << " ";
        // remove top element in stack
        s.pop();
    }

    return 0;
}
