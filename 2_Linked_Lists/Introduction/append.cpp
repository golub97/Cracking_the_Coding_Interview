void append(Node **node, int x);

void append(Node **node, int x)
{
    /* 1. allocate node */
    Node* new_node = new Node();
    
    /* 2. put in the data */
    new_node->value = x;
    
    /* 3. This new node is going to be the last node, so make next of it as nullptr */
    new_node->next = nullptr;
    
    /* 4. If the Linked List is empty, then make the new node as head */
    if((*node) == nullptr)
        (*node) = new_node;
    else
    {
        Node* last = *node; //We won't change content of node pointer (we are passing **).
    
        /* 5. Else traverse till the last node */
        while(last->next != nullptr)
            last = last->next;
        
        /* 6. Change the next of last node */
        last->next = new_node;
    }
}
