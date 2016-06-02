/*有一个数组a[1000]存放0--1000;要求每隔二个数删掉一个数，到末尾时循环至开头继续进行，
求最后一个被删掉的数的原始下标位置。
以7个数为例：
   {0,1,2,3,4,5,6,7} 0-->1-->2（删除）-->3-->4-->5(删除)-->6-->7-->0（删除），如此循环直到最后一个数被删除。

  Author:lp
  date:2016-6-2

  思路：
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

//创建链表节点
typedef struct node
{
	int data;
	struct node* next;
}node;

//创建循环单链表
node* create_list(int num)
{
	node* head = new node;
	head->data = 0;

	node* newnode = NULL;
	node* curr = head;
	int i;
	for(i=1;i<num;i++)
	{
		newnode = new node;
		newnode->data = i;

		curr->next = newnode;
		curr = newnode;
		newnode = NULL;
	}
	curr->next = head;
	return head;
}

//输出打印链表
void Print_list(node* head)
{
	node* curr = head;
	while(curr->next != head)
	{
		cout<<curr->data<<' ';
		curr = curr->next;
	}
	cout<<curr->data<<endl;
}


//输出最后的下标位置
void Print_last_loc(node* head)
{
	int m = 2;
	node* curr = head;
	node* pre = head;
	while(pre->next != head)
	{
		pre = pre->next;	//尾指针
	}

	while(curr != NULL && curr != curr->next)
	{
		if(m)
		{
			m--;
			pre = curr;
			curr = curr->next;
		}
		else
		{
			pre->next = curr->next;
			//cout<<curr->data<<' ';
			delete curr;
			curr = NULL;
			curr = pre->next;
			m = 2;
		}
	}

	if(curr)
	{
		int loc = curr->data;
		loc = loc-1;
		cout<<"loc:"<<loc<<endl;
	}
}

int main(int argc, char const *argv[])
{
	node* head = create_list(1001);
	Print_list(head);
	Print_last_loc(head);
	return 0;
}
