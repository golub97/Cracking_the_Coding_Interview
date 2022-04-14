void deleteNode_by_value(Node** head_ref, int value);

void deleteNode_by_value(Node** head_ref, int value)
{
    // If linked list is empty
    if (*head_ref == nullptr)
        return;
    
    Node *prev_node = (*head_ref);
    // Store head node
    Node* temp = *head_ref;
    
    // If head node itself holds (the key to be deleted)
    if (temp != nullptr && temp->value == value)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // delete old head
    }
    else
    {
        while(temp != nullptr && temp->value != value)
        {
            prev_node = temp;
            temp = temp->next;
        }
        
        if(temp == nullptr)
            return;
            
        prev_node->next = temp->next;
        
        delete temp;
    }
}
