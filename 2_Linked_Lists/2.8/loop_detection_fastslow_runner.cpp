//Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop. 
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

void append(Node** head, char value);
void print_list(Node* head);
Node* FindBeginning(Node* list);

int main()
{
    //First case, when we have intersect.
    Node* head1 = nullptr;

    append(&head1, 'A');
    append(&head1, 'B');
    append(&head1, 'C');
    
    Node* temp1 = head1;
    
    while(temp1->next != nullptr)
        temp1 = temp1->next;
        
    append(&head1, 'D');
    append(&head1, 'E');
    
    Node* temp2 = head1;
    
    while(temp2->next != nullptr)
        temp2 = temp2->next;
        
    temp2->next = temp1;
    
    //A -> B -> C -> D -> E -> C
    Node* loop = FindBeginning(head1);
    
    cout << loop->data;

    return 0;
}

//Fast and Slow Runner
Node* FindBeginning(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    
    /* Find meeting point. This will be LOOP_SIZE - k steps into the linked list. */
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) //Collision
            break;
    }
    
    /* Error check - no meeting point, and therefore no loop*/
    if(fast == nullptr || fast->next == nullptr)
        return nullptr;
        
    /* Move slow to Head. 
    Keep fast at Meeting Point. 
    Each are k steps from the Loop Start. 
    If they move at the same pace, they must meet at Loop Start. */
    
    slow = head;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    /* Both now point to the start of the loop. */ 
    return fast;
}

void append(Node** head, char value)
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
