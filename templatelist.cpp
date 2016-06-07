/*实现一个模版类链表
  Author:lp
  date:2016-6-7
*/

#include <iostream>
using namespace std;

//链表类前置声明
template<class T>
class List;

template<class T>
class Node
{
//声明为友元类
friend class List<T>;

public:
	Node(T _data)
	{
		data = _data;
		next = NULL;
	}
private:
	T data;
	Node<T>* next;
};

template<class T>
class List
{
public:
	//构造函数
	List(int _len)
	{
		head = NULL;
		curr = NULL;
		len = _len;
	}

	//创建链表
	void create_list()
	{
		int i;
		Node<T>* newnode = NULL;
		T _data;
		cin>>_data;
		head = new Node<T>(_data);
		curr = head;
		for(i=1;i<len;i++)
		{
			cin>>_data;
			newnode = new Node<T>(_data);
			curr->next = newnode;
			curr = newnode;
			newnode = NULL;
		}
	}

	//输出链表
	void output_list()
	{
		curr = head;
		while(curr)
		{
			cout<<curr->data<<" ";
			curr = curr->next;
		}
		cout<<endl;
	}

	//析构函数
	~List()
	{
		if(head != NULL)
		{
			delete head;
			head = NULL;
		}
	}
private:
	Node<T>* head;
	Node<T>* curr;
	int len;
};
int main(int argc, char const *argv[])
{
	List<int> list(7);
	list.create_list();
	list.output_list();
	return 0;
}