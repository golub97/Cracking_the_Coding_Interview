//Remove Dups: Write code to remove duplicates from an unsorted linked list. 
//FOLLOW UP 
//How would you solve this problem if a temporary buffer is not allowed? 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node
{
    public:
        int data;
        Node *next;
        Node() : data(0), next(nullptr) {}
};

void append(Node** head_ref, int new_data);
void printList(Node *node);
void remove_duplicates(Node *head_ref);

int main()
{
    /* Start with the empty list */
    Node* head = nullptr;
    
    // Insert 1. So linked list becomes 1->NULL
    append(&head, 1);
    
    // Insert 1. So linked list becomes 1->2->NULL
    append(&head, 2);
    
    // Insert 1. So linked list becomes 1->2->3->NULL
    append(&head, 3);
    
    // Insert 1. So linked list becomes 1->2->3->3->NULL
    append(&head, 3);
    
    // Insert 1. So linked list becomes 1->2->3->3->4->NULL
    append(&head, 4);
    
    // Insert 1. So linked list becomes 1->2->3->3->4->4->NULL
    append(&head, 4);
    
    // Insert 1. So linked list becomes 1->2->3->3->4->4->4->NULL
    append(&head, 4);
    
    // Insert 1. So linked list becomes 1->2->3->3->4->4->4->5->NULL
    append(&head, 5);
    
    // Insert 1. So linked list becomes 1->2->3->3->4->4->4->5->6->NULL
    append(&head, 6);
    
    // Insert 1. So linked list becomes 1->2->3->3->4->4->4->5->6->6->NULL
    append(&head, 6);
    
    printList(head);
    
    cout << endl;
    
    remove_duplicates(head);
    
    printList(head);
    
    cout << endl;

    return 0;
}

void remove_duplicates(Node *head_ref)
{
    unordered_set<int> seen;
    Node* previous = nullptr;
    Node* current = head_ref;
    
    while (current != nullptr)
    {   // If current value is seen before
        if(seen.contains(current->data))  //or seen.find(curr->data) != seen.end()
        {
            previous->next = current->next;
            delete(current);
        }
        else
        {
            seen.insert(current->data);
            previous = current;
        }
        current = previous->next; //free(): double free detected in tcache 2, if current = current->next;
    }
}

void append(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
 
    Node *last = *head_ref; /* used in step 5*/
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = nullptr;
 
    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == nullptr)
    {
        *head_ref = new_node;
        return;
    }
 
    /* 5. Else traverse till the last node */
    while (last->next != nullptr)
    {
        last = last->next;
    }
 
    /* 6. Change the next of last node */
    last->next = new_node;
}

void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << " " << node->data;
        node = node->next;
    }
}
