struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while (cur != NULL)
    {
        if (cur->val == val)
        {
            if (cur == head)
            {
                head = cur->next;
                free(cur);
                cur = head;
            }
            else
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;

}


typedef struct ListNode ListNode;

ListNode* CreateListNode()
{
    ListNode* DummyNode = (ListNode*)malloc(sizeof(ListNode));
    if (DummyNode == NULL)
    {
        exit(-1);
    }
    else
    {
        DummyNode->next = NULL;
    }
    return DummyNode;
}
struct ListNode* removeElements(struct ListNode* head, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    ListNode* DummyNode = CreateListNode();
    DummyNode->next = head;
    head = DummyNode;
    ListNode* prev = head, * cur = head->next;
    while (cur != NULL)
    {
        if (cur->val == val)
        {
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head->next;

}
