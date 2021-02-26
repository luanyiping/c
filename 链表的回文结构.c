typedef struct ListNode ListNode;
ListNode* reverseList(ListNode* head)
{
    ListNode* n1 = NULL;
    ListNode* n2 = head;
    while (n2 != NULL)
    {
        ListNode* n3 = n2->next;
        n2->next = n1;
        n1 = n2;
        n2 = n3;
    }
    return n1;
}
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A)
    {
        ListNode* fast = A;
        ListNode* slow = A;
        ListNode* prev = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverseList(slow);
        while (A != NULL && slow != NULL)
        {
            if (A->val != slow->val)
            {
                return false;
            }
            else
            {
                A = A->next;
                slow = slow->next;
            }
        }
        return true;
    }
};