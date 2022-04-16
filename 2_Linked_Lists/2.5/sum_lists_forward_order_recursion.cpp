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

class PartialSum 
{
    public:
        Node* sum = nullptr;
        int carry = 0;
};

void append(Node** head, int value);
void print_list(Node* head);
Node* addlists(Node* list1, Node* list2);
/* For calculating length */
int calculate_length(Node* list);
/* Pad the list with zeros*/
Node* padList(Node* list, int padding);
/* Helper function to insert node in the front of a linked list*/
Node* insertBefore(Node* list, int data);
PartialSum* addListsHelper(Node* list1, Node* list2);

int main()
{
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    append(&list1, 6);
    append(&list1, 1);
    append(&list1, 7);
    
    append(&list2, 2);
    append(&list2, 9);
    append(&list2, 5);
 
    print_list(list1);
    print_list(list2);
    
    Node* result = addlists(list1, list2);
    
    print_list(result);
    
    return 0;
}

Node* addlists(Node* list1, Node* list2)
{
    int len1 = calculate_length(list1);
    int len2 = calculate_length(list2);
    
    /* Pad the shorter list with zeros - see note (1) */
    if (len1 < len2) 
        list1 = padList(list1, list2 - list1); 
    else
        list2 = padList(list2, list1 - list2);
        
    /* Add lists */
    PartialSum* summ = addListsHelper(list1, list2); 
    
    /* If there was a carry value left over, insert this at the front of the list. */
    /* Otherwise, just return the linked list. */
    
    if (summ->carry == 0) 
        return summ->sum; 
    else
    {
        Node* result = insertBefore(summ->sum, summ->carry);
        return result; 
    }
}

PartialSum* addListsHelper(Node* list1, Node* list2)
{
    if (list1 == nullptr && list2 == nullptr)
    {
        PartialSum* sum = new PartialSum();
        return sum;
    }
    
    /* Add smaller digits recursively*/
    PartialSum* summ = addListsHelper(list1->next, list2->next);

    /* Add carry to current data*/
    int val = summ->carry + list1->data + list2->data;

    /* Insert sum of current digits*/
    Node* full_result = insertBefore(summ->sum, val % 10);

    /* Return sum so far, and the carry value*/
    summ->sum = full_result;
    summ->carry = val/ 10;
    
    return summ;
} 

/* Pad the list with zeros*/
Node* padList(Node* list, int padding)
{
    Node* head = list;
    for (int i = 0; i < padding; i++)
        head = insertBefore(head, 0);
        
    return head;
}

/* Helper function to insert node in the front of a linked list*/
Node* insertBefore(Node* list, int data) 
{
    Node* node = new Node(data);
    
    if (list != nullptr)
        node->next= list;
    
    return node;
} 

int calculate_length(Node* list)
{
    int result = 0;
    
    while(list != nullptr)
    {
        result++;
        list = list->next;
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
