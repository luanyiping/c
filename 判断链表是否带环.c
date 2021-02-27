typedef struct ListNode ListNode;
bool hasCycle(struct ListNode* head)
{
    if (head == NULL)
    {
        return false;
    }
    ListNode* fast = head, * slow = head;
    while (fast)
    {
        if (slow)
        {
            slow = slow->next;
        }
        fast = (fast->next == NULL) ? NULL : fast->next->next;
        if (fast == slow)
        {
            if (fast == NULL)
            {
                return false;
            }
            return true;
        }
    }
    return false;
    
    
     while (fast && fast->next)
    {
       
            slow = slow->next;
            fast =  fast->next->next;
            if (fast == slow)
          {
            
                return true;
           }
    }
    return false;

}
