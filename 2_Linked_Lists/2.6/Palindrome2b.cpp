//Palindrome: Implement a function to check if a linked list is a palindrome.
#include <iostream>
#include <stack>

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
bool isPalindrome(Node* head);

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
    Node* slow = head;
    Node* fast = head;
    
    stack <int> stack;
    
    while(fast != nullptr && fast->next != nullptr)
    {
        stack.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    
    /* Has odd number of elements, so skip the middle element */
    if(fast != nullptr)
        slow = slow->next;
    
    while(slow != nullptr)
    {
        int top = stack.top();
        stack.pop();
        
        /* If values are different, then it's not a palindrome */
        if(top != slow->data)
            return false;
        slow = slow->next;
    }
   
    return true;
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
