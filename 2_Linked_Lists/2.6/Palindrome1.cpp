//Palindrome: Implement a function to check if a linked list is a palindrome. 

#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node(): data(0), next(nullptr) {}
        Node(int value): data(value), next(nullptr) {}
};

void append(Node** head, int value);
void print_list(Node* head);
bool isEqual(Node* one, Node* two);
bool isPalindrome(Node* head);
Node* reverseAndClone(Node* node);

int main()
{
    Node* head = nullptr;
    
    append(&head, 0);
    append(&head, 1);
    append(&head, 2);
    append(&head, 1);
    append(&head, 0);
    
    print_list(head);
    
    cout << isPalindrome(head) << endl;
    
    Node* head1 = nullptr;
    
    append(&head1, 0);
    append(&head1, 1);
    append(&head1, 2);
    append(&head1, 2);
    append(&head1, 1);
    append(&head1, 0);
    
    print_list(head1);
    
    cout << isPalindrome(head1) << endl;

    return 0;
}

bool isPalindrome(Node* head)
{
    Node* reversed = reverseAndClone(head); 
    return isEqual(head, reversed);
}

bool isEqual(Node* one, Node* two)
{
    while(one != nullptr && two != nullptr)
    {
        if(one->data != two->data)
            return false;
            
        one = one->next;
        two = two->next;
    }
    
    return (one == nullptr) && (two == nullptr); 
}

Node* reverseAndClone(Node* node)
{
    Node* head = nullptr;
    
    while(node != nullptr)
    {
        Node* new_node = new Node(node->data);
        new_node->next = head;
        head = new_node;
        node = node->next;
    }
    return head;
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
