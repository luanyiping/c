class Partition {
public:
    ListNode* partition(ListNode* pHead, int x)
    {
        ListNode* LessHead = (ListNode*)malloc(sizeof(ListNode));
        ListNode* GreaterHead = (ListNode*)malloc(sizeof(ListNode));
        LessHead->next = GreaterHead->next = NULL;
        ListNode* LessHeadTail = LessHead;
        ListNode* GreaterHeadTail = GreaterHead;
        ListNode* cur = pHead;
        while (cur != NULL)
        {
            if (cur->val < x)
            {
                LessHeadTail->next = cur;
                LessHeadTail = LessHeadTail->next;
            }
            else
            {
                GreaterHeadTail->next = cur;
                GreaterHeadTail = GreaterHeadTail->next;
            }
            cur = cur->next;
        }
        GreaterHeadTail->next = NULL;
        LessHeadTail->next = GreaterHead->next;
        ListNode* List = LessHead->next;
        free(LessHead);
        free(GreaterHead);
        return List;
    }
};