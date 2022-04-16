//Sum Lists: You have two numbers represented by a linked list, where each node contains a single digit. 
//The digits are stored in reverse order, such that the 1 's digit is at the head of the list. 
//Write a function that adds the two numbers and returns the sum as a linked list.
//EXAMPLE
//Input: (7-> 1 -> 6) + (5 -> 9 -> 2).That is, 617 + 295.
//Output: 2 -> 1 -> 9. That is, 912.
//FOLLOW UP
//Suppose the digits are stored in forward order.
//Repeat the above problem.
//EXAMPLE
//Input:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is, 617 + 295.
//Output: 9 -> 1 -> 2. That is, 912.

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

void append(Node** head, int value);
void print_list(Node* head);
Node* addlists(Node* list1, Node* list2, int carry);

int main()
{
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    append(&list1, 7);
    append(&list1, 1);
    append(&list1, 6);
    
    append(&list2, 5);
    append(&list2, 9);
    append(&list2, 2);
 
    print_list(list1);
    print_list(list2);
    
    int carry = 0;
    
    Node* result = addlists(list1, list2, carry);
    
    print_list(result);
    
    return 0;
}

Node* addlists(Node* list1, Node* list2, int carry)
{
    if(list1 == nullptr && list2 == nullptr && carry == 0)
        return nullptr;
        
    int value = carry;
    
    Node* result = new Node();
    
    if(list1 != nullptr)
        value += list1->data; 
        
    if(list2 != nullptr)
        value += list2->data; 
        
    result->data = value % 10;
    
    if(list1 != nullptr || list2 != nullptr)
    {
        Node* more = addlists(list1 == nullptr ? nullptr : list1->next,
                              list2 == nullptr ? nullptr : list2->next,
                              value >= 10 ? 1 : 0);
        result->next = more;
    }
    return result;
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
