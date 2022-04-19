//Intersection: Given two (singly) linked lists, determine if the two lists intersect. 
//Return the intersecting node. 
//Note that the intersection is defined based on reference, not value. 
//That is, if the kth node of the first linked list is the exact same node (by reference)
//as the jth node of the second linked list, then they are intersecting. 
#include <iostream>
#include <cmath>

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
        Node* tail; 
        int size; 
        Result(Node* tail, int size): tail(tail), size(size) {}
};

void append(Node** head, int value);
void print_list(Node* head);
Node* findintersection(Node* list1, Node* list2);
Result* get_lengths_and_tails(Node* list);
void getKthNode(Node** longer, int k);

int main()
{
    //First case, when we have intersect.
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    
    append(&head1, 3);
    append(&head1, 1);
    append(&head1, 5);
    append(&head1, 9);
    
    append(&head2, 4);
    append(&head2, 6);
    
    //7 2 1 should be added
    
    Node* temp1 = head1;
    Node* temp2 = head2;
    
    while(temp1->next != nullptr)
        temp1 = temp1->next;
    while(temp2->next != nullptr)
        temp2 = temp2->next;
    
    Node* new_1 = new Node(7);
    Node* new_2 = new Node(2);
    Node* new_3 = new Node(1);
    
    new_1->next = new_2;
    new_2->next = new_3;
    new_3->next = nullptr; //not needed
    
    temp1->next = new_1;
    temp2->next = new_1;
    
    print_list(head1);
    print_list(head2);
    
    Node* intersection1  = findintersection(head1, head2);
    
    cout << "Intersection: ";
    
    print_list(intersection1);

    //Second case, when we don't intersect.
    Node* head3 = nullptr;
    Node* head4 = nullptr;
    
    append(&head3, 3);
    append(&head3, 1);
    append(&head3, 5);
    append(&head3, 9);
    append(&head3, 7);
    append(&head3, 2);
    append(&head3, 1);
    
    append(&head4, 4);
    append(&head4, 6);
    append(&head4, 7);
    append(&head4, 2);
    append(&head4, 1);
    
    print_list(head3);
    print_list(head4);
    
    Node* intersection2  = findintersection(head3, head4);
    
    cout << "Intersection: ";
    
    print_list(intersection2);

    return 0;
}

Node* findintersection(Node* list1, Node* list2)
{
    if(list1 == nullptr || list2 == nullptr) return nullptr;
    
    /* Get tail and sizes. */
    Result* result1 = get_lengths_and_tails(list1);
    Result* result2 = get_lengths_and_tails(list2);
    
    /* If different tail nodes, then there's no intersection. */ 
    if(result1->tail != result2->tail)
        return nullptr;
    
    /* Set pointers to the start of each linked list. */ 
    Node* shorter = (result1->size > result2->size) ? list2 : list1; 
    Node* longer  = (result1->size > result2->size) ? list1 : list2;
    
    /* Advance the pointer for the longer linked list by difference in lengths. */ 
    getKthNode(&longer, abs((int)(result1->size - result2->size)));
    
    /* Move both pointers until you have a collision. */ 
    while(shorter != longer)
    {
        shorter = shorter->next;
        longer = longer->next;
    }
    
    /* Return either one. */ 
    return longer;
}

Result* get_lengths_and_tails(Node* list)
{
    if(list == nullptr) return nullptr;
    
    int length = 1; //Length is 1 because we are checking tail->next != nullptr
    Node* tail = list;
 
    while(tail->next != nullptr)
    {
        length++;
        tail = tail->next;
    }
    
    return new Result(tail, length);
}

void getKthNode(Node** longer, int k)
{
    while(k != 0)
    {
        (*longer) = (*longer)->next;
        k--;
    }
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
