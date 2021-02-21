// 1.Ë«Ö¸Õë
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* n1 = NULL;
	ListNode* n2 = head;
	ListNode* n3 = n2->next;
	while (n2 != NULL)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3 != NULL)
		{
			n3 = n3->next;
		}
	}
	return n1;
}

// 2.Í·²å·¨
struct ListNode* reverseList(struct ListNode* head)
{
	ListNode* newNode = NULL, * cur = head;
	while (cur != NULL)
	{
		ListNode* next = cur->next;
		cur->next = newNode;
		newNode = cur;
		cur = next;
	}
	return newNode;
}

// 3.µÝ¹é
struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* ret = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return ret;
}