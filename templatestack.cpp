/*实现一个模版类栈
  Author:lp
  date:2016-6-7
*/

#include <iostream>
using namespace std;

//栈类前置声明
template<class T>
class Stack;

template<class T>
class Node
{
//声明为友元类
friend class Stack<T>;

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
class Stack
{
public:
	Stack()
	{
		top = NULL;
		size = 0;
	}

	void push(T _data)
	{
		Node<T>* newnode = new Node<T>(_data);
		newnode->next = top;
		top = newnode;
		size++;
	}

	bool empty()
	{
		if(size)
			return false;
		return true;
	}

	void pop()
	{
		if(!empty())
		{
			Node<T>* tmp = top;
			top = top->next;
			cout<<tmp->data<<endl;
			delete tmp;
			tmp = NULL;
			size--;
		}
		else
			cout<<"Stack is empty"<<endl;
	}

	void get_top_val()
	{
		if(!empty())
		{
			cout<<top->data<<endl;
		}
		else
			cout<<"Stack is empty"<<endl;
	}

private:
	Node<T>* top;
	int size;
};

int main(int argc, char const *argv[])
{
	Stack<int> st;
	int i;
	for(i=0;i<7;i++)
	{
		st.push(i+1);
	}
	st.get_top_val();
	return 0;
}