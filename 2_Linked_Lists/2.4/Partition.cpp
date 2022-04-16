//Partition: Write code to partition a linked list around a value x, such that all nodes less than x come 
//before all nodes greater than or equal to x. 
//If x is contained within the list the values of x only need to be after the elements less than x (see below). 
//The partition element x can appear anywhere in the //"right partition"; 
//it does not need to appear between the left and right partitions. 
//EXAMPLE 
//Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition= 5] 
//Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8

#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node(): data(0), next(nullptr) {}
        Node(int value): data(value), next(nullptr) {}
};

void append(Node** head, int value);
void print_list(Node* head);
Node* partition(Node* node, int x);

int main()
{
    Node* head = nullptr;

    append(&head, 3);
    append(&head, 5);
    append(&head, 8);
    append(&head, 5);
    append(&head, 10);
    append(&head, 2);
    append(&head, 1);
    
    print_list(head);
    
    
    Node* result = partition(head, 5);
    
    print_list(result);
    
    return 0;
}

/* Pass in the head of the linked list and the value to partition around*/ 
Node* partition(Node* node, int x) 
{ 
    Node* beforeStart = nullptr; 
    Node* beforeEnd = nullptr; 
    Node* afterStart = nullptr; 
    Node* afterEnd = nullptr; 
 
    /* Partition list*/ 
    while (node != nullptr) 
    { 
        Node* next = node->next; 
        node->next = nullptr; 
        
        if (node->data < x) 
        { 
            /* Insert node into end of before list*/ 
            if (beforeStart == nullptr)
            { 
                beforeStart = node; 
                beforeEnd = beforeStart; 
            } 
            else 
            { 
                beforeEnd->next = node; 
                beforeEnd = node; 
            } 

        } 
        else
        { 
            /* Insert node into end of after list*/ 
            if (afterStart == nullptr) 
            { 
                afterStart = node; 
                afterEnd = afterStart; 
            }
            else
            { 
                afterEnd->next = node; 
                afterEnd = node;
            } 
        }
        node = next; 
    } 

    if (beforeStart == nullptr)
        return afterStart; 

    /* Merge before list and after list */ 
    beforeEnd->next = afterStart; 
    return beforeStart; 
}

void append(Node** head, int value)
{
    Node* new_node = new Node(value);
    
    if((*head) == nullptr)
    {
        (*head) = new_node;
        return;
    }
    
    Node* last = (*head);
    
    while(last->next != nullptr)
        last = last->next;
    
    last->next = new_node;
}

void print_list(Node* head)
{
    while(head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    
    cout << "nullptr" << endl;
}
