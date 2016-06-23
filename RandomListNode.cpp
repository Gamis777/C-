/*输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点）。
  
  struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

思路：
	1.首先将节点赋值，并将该节点插入到赋值节点的下一个节点
	2.节点的random指针指向为其前一个指针指向的random指向的next
	3.将一个链表分成两个
*/


RandomListNode* clone(RandomListNode* pHead)
{
	if(!pHead)
		return NULL;
	//next指针
	RandomListNode* curr = pHead;
	while(curr)
	{
		RandomListNode* newnode = new RandomListNode(curr->label);
		newnode->next = curr->next;
		curr->next = newnode;
		curr = newnode->next;
	}
	//random指针
	curr = pHead;
	while(curr)
	{
		RandomListNode* newnode = curr->next;
		if(curr->random)
		{
			newnode->random = curr->random->next;
		}
		curr = newnode->next;
	}

	//拆分链表
	RandomListNode* head = pHead->next;
	RandomListNode* tmp = NULL;
	curr = pHead;
	while(curr->next)
	{
		tmp = curr->next;
		curr->next = tmp->next;
		curr = tmp;
	}
	return head;
}
