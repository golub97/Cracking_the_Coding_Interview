//Remove Dups: Write code to remove duplicates from an unsorted linked list. 
//FOLLOW UP 
//How would you solve this problem if a temporary buffer is not allowed? 

#include <iostream>
#include <bits/stdc++.h>
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
void print_list(Node * head);
void remove_duplicates(Node* head);

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
    
    print_list(head);
    
    remove_duplicates(head);
    
    print_list(head);
    
    return 0;
}

void append(Node** head, int value)
{
    Node* new_node = new Node(value);
    
    if(*head == nullptr)
    {
        *head = new_node;
        return;
    }
    
    Node* last = *head;
    
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

void remove_duplicates(Node* head)
{
    Node* current = head;
    
    while(current != nullptr)
    {
        Node* runner = current;
        
        while(runner->next != nullptr)
        {
            if(current->data == runner->next->data)
            {
                runner->next = runner->next->next;
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}
