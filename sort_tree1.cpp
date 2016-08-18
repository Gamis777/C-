/*简单构造一个排序二叉树
  性质：
      对于树中的任意一个节点，必有其左孩子的值小于该节点的值
      右孩子的值大于该节点的值
  Author:lp
  date:2016/8/18
*/

#include <iostream>
using namespace std;

//树类前置声明
template<class T>
class Tree;

//创建节点类
template<class T>
class Node
{
friend class Tree<T>;
public:
	Node(T _val)
	{
		val = _val;
		left = NULL;
		right = NULL;
	}
private:
	T val;
	Node<T>* left;
	Node<T>* right;
};

//创建树类
template<class T>
class Tree
{
public:
	Tree();	//构造函数
	~Tree();	//析构函数
	void PreTree();	//前序遍历
	void MidTree();	//中序遍历
	void LastTree();	//后序遍历
	const T& findmin();	//查找最小值，并返回最小值,利用递归
	const T& findmax();	//查找最大值，并返回最大值 利用循环
	Node<T>* contain(const T& x)const;	//二叉树中是否包含指定值的元素
	bool isEmpty() const;	//判断二叉树是否为空
	void insert(const T& x) ;	//向二叉查找树中插入指定值 	
 	void _remove(const T& x) ;	//删除二叉查找树的指定值
 	void destroy() ; 	//销毁二叉树

private:
	Node<T>* Troot;

	void PreTree(Node<T>* tree) const;
	void MidTree(Node<T>* tree) const;
	void LastTree(Node<T>* tree) const;
	Node<T>* findmin(Node<T>* tree) const;
	Node<T>* findmax(Node<T>* tree) const;
	Node<T>* contain(const T& x,Node<T>* tree) const;
	bool isEmpty(Node<T>* tree) const;
	void insert(Node<T>* newnode,Node<T>* &tree);
	void _remove(const T& x,Node<T>* &tree);
	void destroy(Node<T>* &tree);
};

/*构造函数*/
template<class T>
Tree<T>::Tree():Troot(NULL)	//以参数列表方式初始化
{
	Troot = NULL;
}

/*析构函数*/
template<class T>
Tree<T>::~Tree()
{
	destroy();
}

/*前序遍历*/
template<class T>
void Tree<T>::PreTree(Node<T>* tree) const
{
	if(tree != NULL)
	{
		cout<<tree->val<<" ";
		PreTree(tree->left);
		PreTree(tree->right);
	}
}
template<class T>
void Tree<T>::PreTree() 
{
	PreTree(Troot);
}

/*中序遍历*/
template<class T>
void Tree<T>::MidTree(Node<T>* tree) const
{
	if(tree != NULL)
	{
		MidTree(tree->left);
		cout<<tree->val<<" ";
		MidTree(tree->right);
	}
}
template<class T>
void Tree<T>::MidTree()
{
	MidTree(Troot);
}

/*后序遍历*/
template<class T>
void Tree<T>::LastTree(Node<T>* tree) const
{
	if(tree != NULL)
	{
		LastTree(tree->left);
		LastTree(tree->right);
		cout<<tree->val<<" ";
	}
}
template<class T>
void Tree<T>::LastTree()
{
	LastTree(Troot);
}

/*查找最小值，并返回最小值,利用递归*/
template<class T>
Node<T>* Tree<T>::findmin(Node<T>* tree) const
{
	if(tree == NULL)
		return NULL;
	if(tree->left == NULL)
		return tree;
	else
		return findmin(tree->left);
}
template<class T>
const T& Tree<T>::findmin() 
{
	return findmin(Troot)->val;
}

/*查找最大值，并返回最大值 利用循环*/
template<class T>
Node<T>* Tree<T>::findmax(Node<T>* tree) const
{
	if(tree == NULL)
		return NULL;
	while(tree->right != NULL)
	{
		tree = tree->right;
	}
	return tree;
}
template<class T>
const T& Tree<T>::findmax()
{
	return findmax(Troot)->val;
}

 /*二叉树中是否包含指定值的元素*/
template<class T>
Node<T>* Tree<T>::contain(const T& x,Node<T>* tree) const
{
	if(tree == NULL || tree->val == x)
		return tree;
	if(x > tree->val)
	{
		contain(x,tree->right);
	}
	else
	{
		contain(x,tree->left);
	}
}
template<class T>
Node<T>* Tree<T>::contain(const T& x) const
{
	return contain(x,Troot);
}

/*判断二叉树是否为空*/
template<class T>
bool Tree<T>::isEmpty(Node<T>* tree) const
{
	if(tree == NULL)
		return true;
	else
		return false;
}
template<class T>
bool Tree<T>::isEmpty() const
{
	return isEmpty(Troot);
}

/*向二叉查找树中插入指定值*/
template<class T>
void Tree<T>::insert(Node<T>* newnode,Node<T>* &tree)
{
	Node<T>* y = NULL;
	Node<T>* x = tree;

	while(x != NULL)
	{
		y = x;
		if(newnode->val < x->val)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	if(y != NULL)
	{	
		if(newnode->val < y->val)
			y->left = newnode;
		else
			y->right = newnode;
	}
	else
		tree = newnode;
}
template<class T>
void Tree<T>::insert(const T& x)
{
	Node<T>* newnode = new Node<T>(x);
	newnode->left = NULL;
	newnode->right = NULL;
	insert(newnode,Troot);
}

/*删除二叉查找树的指定值
 *1.当该节点没有子节点，直接删除
 *2.当该节点有一个节点，将该节点删除，子节点占据该位置
 *3.当该节点有两个节点，先在该节点的右子树找到最小值节点，昂后用最小值代替该
 *节点，再删除最小值节点
*/
template<class T>
void Tree<T>::_remove(const T& x,Node<T>* &tree)
{
	Node<T>* node = contain(x,tree);
	if(node == NULL)
		return;

	if(node->left!=NULL && node->right!=NULL)
	{
		node->val = findmin(node->right)->val;
		findmin(node->right)->val = x;
		_remove(x,tree);
	}
	if(node->left==NULL && node->right==NULL)
	{
		delete node;
		node = NULL;
	}
	else
	{
		Node<T>* tmp = node;
		node = (node->left != NULL)?node->left:node->right;
		delete tmp;
		tmp = NULL;
	}
}
template<class T>
void Tree<T>::_remove(const T& x)
{
	_remove(x,Troot);
}

/*销毁二叉树*/
template<class T>
void Tree<T>::destroy(Node<T>* &tree)
{
	if(tree == NULL)
		return;
	if(tree->left != NULL)
		destroy(tree->left);
	if(tree->right != NULL)
		destroy(tree->right);

	delete tree;
	tree = NULL;
}
template<class T>
void Tree<T>::destroy()
{
	destroy(Troot);
}
int main(int argc, char const *argv[])
{
	Tree<int> mytree;
	mytree.insert(22);
	mytree.insert(12);
	mytree.insert(56);
	mytree.insert(34);
	mytree.insert(2);
	mytree.insert(17);
	mytree.insert(25);
	mytree.insert(27);
	mytree.insert(13);
	mytree.insert(11);
	mytree.PreTree();
	cout<<endl;
	mytree.MidTree();
	cout<<endl;
	mytree.LastTree();
	cout<<endl;
	cout<<"最小值："<<mytree.findmin()<<endl;
	cout<<"最大值："<<mytree.findmax()<<endl;
	cout<<"是否包含："<<mytree.contain(17)<<endl;
	cout<<"是否为空："<<mytree.isEmpty()<<endl;
	mytree._remove(12);
	mytree.PreTree();
	cout<<endl;
	mytree.destroy();
	cout<<"是否为空："<<mytree.isEmpty()<<endl;
	return 0;
}