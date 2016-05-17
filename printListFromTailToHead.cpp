#include <iostream>
#include <vector>
using namespace std;
/*输入一个链表，从尾到头打印链表每个节点的值。
 思路：利用vector容器存储链表内容
 std::vector<int>::insert(loc,int val)
 在该位置之前插入值 返回的是该位置
 */
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}ListNode;

ListNode* createlist(int data)
{
	ListNode* head=(ListNode*)malloc(1*sizeof(ListNode));
	head->val=-100;
	head->next=NULL;
	ListNode* newnode=NULL;
	ListNode* curr=head;
	int i;
	for(i=0;i<data;i++)
	{
		newnode=(ListNode*)malloc(1*sizeof(ListNode));
		while(newnode==NULL)
		{
			newnode=(ListNode*)malloc(1*sizeof(ListNode));
		}
		newnode->val=i+1;
		newnode->next=NULL;

		curr->next=newnode;	
		curr=newnode;
		newnode=NULL;
	}
	return head;
}

vector<int> printListFromTailToHead(ListNode* head)
{
	std::vector<int> v1;
	while(head!=NULL)
	{
		v1.insert(v1.begin(),head->val);
		head=head->next;
	}
	return v1;
}
int main(int argc, char const *argv[])
{
	ListNode* head=createlist(10);
	std::vector<int> v2;
	v2=printListFromTailToHead(head);
	std::vector<int>::iterator it;
	for(it=v2.begin();it!=v2.end();it++)
	{
		cout<<*it<<'\t';
	}
	cout<<endl;
	return 0;
}