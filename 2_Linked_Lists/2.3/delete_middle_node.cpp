//Delete Middle Node: Implement an algorithm to delete a node in the middle
//(i.e., any node but  the first and last node, not necessarily the exact middle) 
//of a singly linked list, given only access to that node. 
//EXAMPLE 
//Input: the node c from the linked lista->b->c->d->e->f 
//Result: nothing is returned, but the new linked list looks like a->b->d->e->f 

#include <iostream>

using namespace std;

class Node
{
    public:
        char data;
        Node* next;
        Node(): data(' '), next(nullptr) {}
        Node(char value): data(value), next(nullptr) {}
};

void append(Node** head, char symbol);
void print_list(Node* head);
void delete_middle_node(Node* middle);

int main()
{
    Node* head = nullptr;
    
    append(&head, 'a');
    append(&head, 'b');
    append(&head, 'c');
    append(&head, 'd');
    append(&head, 'e');
    append(&head, 'f');
    
    print_list(head);
    
    Node* point_to_c = head->next->next;
    
    print_list(point_to_c);
    
    delete_middle_node(point_to_c);
    
    print_list(head);
    
    return 0;
}

void delete_middle_node(Node* middle)
{
    if((middle == nullptr) || (middle->next == nullptr))
        return;
        
    Node* next_node = middle->next;
    middle->data = next_node->data;
    middle->next = next_node->next;
    delete next_node;
}

void append(Node** head, char symbol)
{
    Node* new_node = new Node(symbol);
    
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
