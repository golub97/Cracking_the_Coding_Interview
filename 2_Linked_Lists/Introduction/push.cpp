void push(Node **node, int x);

void push(Node **node, int x)
{
    /* 1. allocate node */
    Node* new_node = new Node();
    
    /* 2. put in the data */
    new_node->value = x;
    
    /* 3. Make next of new node as head */
    new_node->next = (*node);
    
    /* 4. move the head to point to the new node */
    (*node) = new_node;
}
