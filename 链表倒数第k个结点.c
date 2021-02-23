struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int count = 0;
    struct ListNode* tail = head;
    while (tail != NULL)
    {
        count++;
        tail = tail->next;
    }
    if (k > count)
    {
        return NULL;
    }
    struct ListNode* start = head;
    int i = 0;
    for (i = 0; i < count - k; i++)
    {
        start = start->next;
    }
    return start;
}


struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* fast = head, * slow = head;
    while (k--)
    {
        fast = fast->next;
    }
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}


