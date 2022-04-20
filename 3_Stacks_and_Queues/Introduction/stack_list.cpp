// C++ program for linked list implementation of stack
#include <bits/stdc++.h>
using namespace std;
 
// A structure to represent a stack
class StackNode 
{
public:
    int data;
    StackNode* next;
    StackNode(): data(-1), next(nullptr) {}
};
    
StackNode* newNode(int data);
bool isEmpty(StackNode* root);
void push(StackNode** root, int data);
int pop(StackNode** root);
int peek(StackNode* root);

// Driver code
int main()
{
    StackNode* root = NULL;
 
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
 
    cout << pop(&root) << " popped from stack\n";
 
    cout << "Top element is " << peek(root) << endl;
     
    cout<<"Elements present in stack : ";
     //print all elements in stack :
    while(!isEmpty(root))
    {
        // print top element in stack
        cout << peek(root) << " ";
        // remove top element in stack
        pop(&root);
    }
 
    return 0;
}

StackNode* newNode(int data)
{
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
 
bool isEmpty(StackNode* root)
{
    return !root;
}

void push(StackNode** root, int data)
{
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = *root;
    *root = stackNode;
    cout << data << " pushed to stack\n";
}

int pop(StackNode** root)
{
    if(isEmpty(*root))
    {
        cout << "Stack Underflow";
        return INT_MIN;
    }
    
    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    
    return popped;
}

int peek(StackNode* root)
{
    if(isEmpty(root))
    {
        cout << "Stack is empty";
        return INT_MIN;
    }
    
    return root->data;
}
