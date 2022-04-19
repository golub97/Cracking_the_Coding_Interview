//Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop. 
#include <iostream>
#include <unordered_set>

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

Node* FindBeginning(Node* list)
{
    unordered_set<Node*> seen;
    
    while(list != nullptr)
    {
        if(seen.contains(list))
        {
            return list;
        }
        else
        {
            seen.insert(list);
        }
        list = list->next;
    }
    
    return nullptr;
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
