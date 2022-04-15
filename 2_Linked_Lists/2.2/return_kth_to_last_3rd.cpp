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
Node* nthTolast(Node* head, int kth);

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
    
    int kth = 1;
    
    cout << kth << " element is: " << (nthTolast(head, kth))->data << endl;
    
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

Node* nthTolast(Node* head, int kth)
{
    Node* p1 = head;
    Node* p2 = head;
    
    for(int i = 0; i < kth && p1 != nullptr; ++i)
    {
        if(p1 == nullptr) return nullptr;
        p1 = p1->next;
    }
    
    while(p1 != nullptr)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return p2;
}
