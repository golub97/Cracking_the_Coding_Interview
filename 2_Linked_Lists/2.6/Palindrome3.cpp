//Palindrome: Implement a function to check if a linked list is a palindrome.
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

class Result 
{
    public:
        Node* node; 
        bool result; 
        Result(): node(nullptr), result(false) {}
        Result(Node* node_n, bool result_n): node(node_n), result(result_n) {}
};

void append(Node** head, int value);
void print_list(Node* head);
bool isPalindrome(Node* head);
Result* isPalindromeRecurse(Node* head, int length);
int lengthOfList(Node* n); 

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
    int length = lengthOfList(head);
    Result* p = isPalindromeRecurse(head, length); 
    
    return p->result; 
} 

Result* isPalindromeRecurse(Node* head, int length) 
{ 
    if (head == nullptr || length <= 0) //Even number of nodes
        return new Result(head, true); 
    else if (length == 1)               //Odd number of nodes 
        return new Result(head->next, true); 

    /* Recurse on sublist. */
    Result* res = isPalindromeRecurse(head->next, length - 2); 

    /*If child calls are not a palindrome, pass back up a failure. */
    if (!res->result || res->node == nullptr) 
        return res; 

    /*Check if matches corresponding node on other side. */
    res->result = (head->data == res->node->data); 

    /* Return corresponding node. */
    res->node= res->node->next; 

    return res; 
}

int lengthOfList(Node* n) 
{ 
    int size = 0; 
    while (n != nullptr) 
    { 
        size++; 
        n = n->next; 
    } 
    return size; 
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
