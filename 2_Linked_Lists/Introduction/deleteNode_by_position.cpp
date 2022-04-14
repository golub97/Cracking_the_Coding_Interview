void deleteNode_by_position(Node** head_ref, unsigned int position);

void deleteNode_by_position(Node** head_ref, unsigned int position)
{
    // If linked list is empty
    if (*head_ref == nullptr)
        return;
    
    // Store head node
    Node* temp = *head_ref;
    
    // If head needs to be removed
    if(position == 0)
    {
        // Change head
        *head_ref = temp->next;
        
        // Delete old head
        delete(temp);
        
        return;
    }     
    
    // Find previous node of the node to be deleted        
    for(int i = 0; (i < position - 1) && (temp != nullptr); ++i)
        temp = temp->next;
        
    // If position is more than number of nodes
    if (temp == nullptr || temp->next == nullptr)
        return;
        
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node* nodeToDelete = temp->next;
    
    temp->next = temp->next->next; //  (*((*temp).next)).next
        
    delete(nodeToDelete); 
}
