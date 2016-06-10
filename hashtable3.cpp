/*用链表法解决哈希表的冲突*/
#include <iostream>
#define N 20
using namespace std;

//链表类前置声明
template<class T>
class List;

//哈希表类前置声明
template<class T>
class hashtable;


//节点类
template<class T>
class Node
{
friend class List<T>;
friend class hashtable<T>;
template<class T1>
friend ostream& operator << (ostream& out,Node<T1> tmp);
template<class T2>
friend ostream& operator << (ostream& out,List<T2> l1);
public:
	Node(T _value)
	{
		value = _value;
		next = NULL;
		lptr = NULL;
	}

	//重载 == 符号
	bool operator == (Node<T> tmp)
	{
		return this->value == tmp->value;
	}
private:
	T value;
	Node<T>* next;
	List<T>* lptr;
};
//重载 << 符号
template<class T>
ostream& operator << (ostream& out,Node<T> tmp)
{
	out<<tmp.value<<endl;
	return out;
}


//链表类
template<class T>
class List
{
template<class T1>
friend ostream& operator << (ostream& out,List<T1> l1);
public:
	List(Node<T>* tmp = NULL)
	{
		head = tmp;
		curr = NULL;
	}

	//插入节点函数
	void push_back(Node<T>* newnode)
	{
		if(head == NULL)
		{
			head = newnode;
			curr = head;
		}
		else
		{
			curr->next = newnode;
			curr = newnode;
		}
		newnode = NULL;
	}

	//删除节点函数
	void list_delete(Node<T>* tmp)
	{
		if(tmp->next == NULL)
		{
			delete tmp;
			tmp = NULL;
		}
		if(tmp->next != NULL && tmp->next->next == NULL)
		{
			Node<T>* t1 = tmp->next;
			tmp->value = t1->value;
			delete t1;
			t1 = NULL;
			tmp->next = NULL;
		}
		if(tmp->next != NULL && tmp->next->next != NULL)
		{
			Node<T>* t1 = tmp->next;
			Node<T>* t2 = tmp->next->next;
			tmp->value = t1->value;
			tmp->next = t2;
			t1->next = NULL;
			delete t1;
			t1 = NULL;
		}
	}

	//判断链表中指定的值是否存在
	bool list_exists(Node<T>* tmp)
	{
		bool exists = false;
		if(tmp == NULL)
			return exists;
		else
		{
			curr = head;
			while(curr)
			{
				if(curr->value == tmp->value)
				{
					exists = true;
					break;
				}
				curr = curr->next;
			}
		}
		return exists;
	}
private:
	Node<T>* head;
	Node<T>* curr;
};

//重载 << 符号
template<class T>
ostream& operator << (ostream& out,List<T> l1)
{
	Node<T>* tmp = l1.head;
	while(tmp)
	{
		out<<*tmp;
		tmp = tmp->next;
	}
	return out;
}


//hash 表类
template<class T>
class hashtable
{
typedef int (*hash)(T value);	//指向哈希函数的函数指针
public:
	hashtable(hash _fptr)
	{
		fptr = _fptr;
		int i;
		for(i=0;i<N;i++)
		{
			table[i] = NULL;
		}
	}

	//hash table 插入数据
	void hash_insert(T value)
	{
		int key = fptr(value);
		Node<T>* newnode = NULL;
		if(table[key] == NULL)
		{
			newnode = new Node<T>(value);
			newnode->lptr = new List<T>();
			table[key] = newnode;
		}
		else
		{
			newnode = new Node<T>(value);
		}
		table[key]->lptr->push_back(newnode);	//插入到链表的末尾
	}

	//判断哈希表中是否存在指定值的元素
	bool hash_find(T value)
	{
		bool find = false;
		int key = fptr[value];
		if(table[key] == NULL)
			return find;
		else
		{
			Node<T>* tmp = new Node<T>(value);
			List<T>* l1 = table[key]->lptr;
			find = l1.list_exists(tmp);
		}
		return find;
	}	

	//删除哈希表中一个值
	void hash_delete(T value)
	{
		int key = fptr(value);
		if(table[key] == NULL)
			return;
		else
		{
			Node<T>* tmp = new Node<T>(value);
			List<T>* l1 = table[key]->lptr;
			bool find = l1->list_exists(tmp);
			if(find)
			{
				l1->list_delete(tmp);
			}
		}
	}

	//输出哈希表中内容
	void hash_output()
	{
		int i;
		for(i=0;i<N;i++)
		{
			if(table[i] != NULL)
			{
				List<T>* l1 = table[i]->lptr;
				cout<<*l1<<endl;
			}
		}
	}
private:
	hash fptr;
	Node<T>* table[N];
} ;

//外置哈希函数
int hash_fun(string value)
{
	int i;
	int sum = 0;
	for(i=0;i<value.length();i++)
	{
		sum = sum + value[i];
	}
	return sum % N;
}
int main(int argc, char const *argv[])
{
	hashtable<string> h1(hash_fun);
	h1.hash_insert("asdfasdfasdf");
	h1.hash_insert("123123124");
	h1.hash_insert("1232ewtrwsdf");
	h1.hash_insert("sdfsd");
	h1.hash_insert("asdfasdfasdf");
	h1.hash_insert("ghjkghjk");
	h1.hash_insert("asdfasdfasdf");
	h1.hash_insert("aaaa");
	h1.hash_insert("aaaa");
	h1.hash_insert("ojopujoihn");
	h1.hash_output();
	return 0;
}