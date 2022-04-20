//Three in One: Describe how you could use a single array to implement three stacks. 
#include <bits/stdc++.h>
using namespace std;
 
class FixedMultiStack
{
    private:
        int numberOfStacks = 3;
        int stackCapacity;
        int* values;
        int* sizes;
    public:
        FixedMultiStack(int stackSize) 
        {
            stackCapacity = stackSize;
            values = new int[stackSize * numberOfStacks];
            sizes = new int[numberOfStacks];
        } 

        /* Push value onto stack. */
        void push(int stackNum, int value)
        {
            if(isFull(stackNum))
            {
                cout << "Stackoveflow occured\n";
                return;
            }
            
            sizes[stackNum]++;
            values[indexOfTop(stackNum)] = value;
        }
        
        /* Pop item from top stack. */
        int pop(int stackNum)
        {
            if(isEmpty(stackNum))
                return INT_MIN; //or throw new EmptyStackException(); 
            else
            {
                int value = values[indexOfTop(stackNum)]; //Get top
                values[indexOfTop(stackNum)] = 0; //Clear
                sizes[stackNum]--; //Shrink
                return value;
            }
        }
        
        /* Return top element. */
        int peek(int stackNum)
        {
            if(isEmpty(stackNum))
                return INT_MIN; //or throw new EmptyStackException(); 
            else
            {
                return values[indexOfTop(stackNum)];
            }
        }
        
        /* Return if stack is empty. */
        bool isEmpty(int stackNum)
        {
            return sizes[stackNum] == 0;
        }
        
        /* Return if stack is full. */ 
        bool isFull(int stackNum)
        {
            return sizes[stackNum] == stackCapacity;
        }
        
        /* Returns index of the top of the stack. */ 
        int indexOfTop(int stackNum)
        {
            int offset = stackCapacity * stackNum;
            int size = sizes[stackNum];
            return offset + size - 1;
        }
};

int main()
{
    FixedMultiStack* stacks = new FixedMultiStack(3);
    
    stacks->push(0, 1);
    stacks->push(0, 2);
    stacks->push(0, 3);
    
    // print top element in stack 0
    cout << "Top element in stack 0 is " << stacks->peek(0) << endl;
    cout << stacks->pop(0) << " popped from stack 0\n";
    cout << "Top element in stack 0 is " << stacks->peek(0) << endl;
    
    cout <<"Elements present in stack 0: ";
    while(!stacks->isEmpty(0))
    {
        // print top element in stack
        cout << stacks->peek(0) << " ";
        // remove top element in stack
        stacks->pop(0);
    }
    
    stacks->push(1, 4);
    stacks->push(1, 5);
    stacks->push(1, 6);
    
    // print top element in stack 1
    cout << "\nTop element in stack 1 is " << stacks->peek(1) << endl;
    cout << stacks->pop(1) << " popped from stack 1\n";
    cout << "Top element in stack 1 is " << stacks->peek(1) << endl;
    
    cout <<"Elements present in stack 1: ";
    while(!stacks->isEmpty(1))
    {
        // print top element in stack
        cout << stacks->peek(1) << " ";
        // remove top element in stack
        stacks->pop(1);
    }
    
    stacks->push(2, 7);
    stacks->push(2, 8);
    stacks->push(2, 9);
    
    // print top element in stack 2
    cout << "\nTop element in stack 2 is " << stacks->peek(2) << endl;
    cout << stacks->pop(2) << " popped from stack 2\n";
    cout << "Top element in stack 2 is " << stacks->peek(2) << endl;
    
    cout <<"Elements present in stack 2: ";
    while(!stacks->isEmpty(2))
    {
        // print top element in stack
        cout << stacks->peek(2) << " ";
        // remove top element in stack
        stacks->pop(2);
    }
    
    return 0;
}
