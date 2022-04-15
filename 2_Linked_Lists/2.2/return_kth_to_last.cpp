//Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.

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
int printKthToLast(Node* head, int kth);

int main()
{
    Node* head = nullptr;
    
    append(&head, 1);
    append(&head, 2);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);
    append(&head, 7);
    append(&head, 7);
    append(&head, 8);
    
    print_list(head);
    
    printKthToLast(head, 1);
    
    return 0;
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
    {
        last = last->next;
    }
    
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

int printKthToLast(Node* head, int kth)
{
    if(head == nullptr)
        return 0;
        
    int index = printKthToLast(head->next, kth) + 1;
    
    if(index == kth)
        cout << kth << " element is: " << head->data << endl;
        
    return index; 
}
