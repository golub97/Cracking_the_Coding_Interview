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

class Index 
{
    public:
        int value;
        Index(): value(0) {}
};

void append(Node** head, int value);
void print_list(Node* head);
Node* kthTolast(Node* head, int k);
Node* kthToLast(Node* head, int k, Index* idx);

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
    
    int kth = 5;
    
    Node* result = kthTolast(head, kth);
    
    cout << kth << " element is: " << result->data << endl;
    
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

Node* kthTolast(Node* head, int k) 
{
    Index* idx = new Index();
    return kthToLast(head, k, idx);
} 

Node* kthToLast(Node* head, int k, Index* idx) 
{
    if (head == nullptr)
        return nullptr;

    Node* new_node = kthToLast(head->next, k, idx);
    idx->value = idx->value + 1;
    
    if (idx->value == k)
        return head;

    return new_node;
}
