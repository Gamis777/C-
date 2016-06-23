/*存在一个链表，首先在每一个节点后插入一个节点，，将这个链表的节点接替分离成两个链表，并返回第二个链表
  Author:lp
  date:2016-6-21

 思路：*/
#include <iostream>
using namespace std;

//创建链表节点
typedef struct Node
{
	int data;
	struct Node* next;
}Node;

//建立链表
Node* create_list(int num)
{
	Node* head = new Node;
	head->data = 1;
	head->next = NULL;

	Node* curr = head;
	Node* newnode = NULL;
	int i;
	for(i=1;i<num;i++)
	{
		newnode = new Node;
		newnode->data = i+1;
		newnode->next = NULL;

		curr->next = newnode;
		curr = newnode;
		newnode = NULL;
	}
	return head;
}

void Print_list(Node* head)
{
	Node* curr = head;
	while(curr)
	{
		cout<<curr->data<<" ";
		curr = curr->next;
	}
	cout<<endl;
}


//方法1
Node* separate_list_1(Node* head)
{
	Node* curr = head;
	int data;
	while(curr)
	{
		Node* newnode = new Node;
		scanf("%d",&data);
		newnode->data = data;
		newnode->next = NULL;

		newnode->next = curr->next;
		curr->next = newnode;
		curr = newnode->next;
	}

	Node* Shead = head->next;
	Node* tmp = NULL;
	curr = head;
	while(curr->next)
	{
		tmp = curr->next;
		curr->next = tmp->next;
		curr = tmp;
	}
	return Shead;
}

int main(int argc, char const *argv[])
{
	Node* head = create_list(7);
	Print_list(head);
	Node* Shead = separate_list_1(head);
	Print_list(Shead);
	return 0;
}
