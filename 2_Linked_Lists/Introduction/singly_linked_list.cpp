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
 
void push(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}
 
void insertAfter(Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == nullptr)
    {
        cout<<"The given previous node cannot be NULL";
        return;
    }
 
    /* 2. allocate new node */
    Node* new_node = new Node();
 
    /* 3. put in the data */
    new_node->data = new_data;
 
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
 
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
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

void deleteNode_by_value(Node** head_ref, int key)
{
     
    // Store head node
    Node* temp = *head_ref;
    Node* prev = nullptr;
     
    // If head node itself holds
    // the key to be deleted
    if (temp != nullptr && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
 
    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
    else
    {
        while (temp != nullptr && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
 
        // If key was not present in linked list
        if (temp == nullptr)
            return;
 
        // Unlink the node from linked list
        prev->next = temp->next;
 
        // Free memory
        delete temp;
    }
}

void deleteNode_by_position(Node** head_ref, int position)
{
 
    // If linked list is empty
    if (*head_ref == NULL)
        return;
 
    // Store head node
    Node* temp = *head_ref;
 
    // If head needs to be removed
    if (position == 0) {
 
        // Change head
        *head_ref = temp->next;
 
        // Free old head
        free(temp);
        return;
    }
 
    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
 
    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;
 
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node* next = temp->next->next;
 
    // Unlink the node from linked list
    free(temp->next); // Free memory
 
    // Unlink the deleted node from list
    temp->next = next;
}
 
void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << " " << node->data;
        node = node->next;
    }
}
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node* head = nullptr;
     
    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);
     
    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    push(&head, 7);
     
    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    push(&head, 1);
     
    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    append(&head, 4);
     
    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);
     
    cout << "Created Linked list is: ";
    printList(head);
    
    cout << endl;
    
    deleteNode_by_value(&head, 3);
    cout << "Linked List after Deletion of value 3: ";
    printList(head);
    
    cout << endl;

    deleteNode_by_position(&head, 2);
    cout << "Linked List after Deletion at position 4: ";
    printList(head);
     
    return 0;
}
