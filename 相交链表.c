typedef struct ListNode ListNode;
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    ListNode* curA = headA, * curB = headB;
    int la = 0, lb = 0;
    while (curA != NULL)
    {
        la++;
        curA = curA->next;
    }
    while (curB != NULL)
    {
        lb++;
        curB = curB->next;
    }
    curA = headA, curB = headB;
    int count = (lb > la) ? (lb - la) : (la - lb);
    int i = 0;
    for (i = 0; i < count; i++)
    {
        if (lb > la)
        {
            curB = curB->next;
        }
        else
        {
            curA = curA->next;
        }
    }
    while (curA && curB)
    {
        if (curA != curB)
        {
            curA = curA->next;
            curB = curB->next;
        }
        else
        {
            return curA;
        }
    }
    return NULL;
}