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
void printKthToLast(Node* head, int kth);

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
    
    printKthToLast(head, 5);
    
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

void printKthToLast(Node* head, int kth)
{
    int no_elements = 0;
    Node* temp = head;
    
    while(head != nullptr)
    {
        no_elements++;
        head = head->next;
    }
    
    for(int i = 0; i < (no_elements - kth) && temp != nullptr; ++i)
    {
        temp = temp->next;
    }
    
    if(temp == nullptr)
        cout <<"something is wrong" << endl;
        
    cout << kth << " element is: " << temp->data << endl;
}
