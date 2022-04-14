void insertAfter(Node* prev_node, int new_data);

void insertAfter(Node* prev_node, int new_data)
{
    /*1. check if the given prev_node is NULL */
    if (prev_node == nullptr)
    {
        std::cout << "The given previous node cannot be nullptr";
        return;
    }
 
    /* 2. allocate new node */
    Node* new_node = new Node();
 
    /* 3. put in the data */
    new_node->value = new_data;
 
    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;
 
    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}
