/*实现一个排序二叉树
  Author:lp
  date:2016/6/24

   二叉排序树是一种动态树表。
   二叉排序树的定义：二叉排序树或者是一棵空树，
   或者是一棵具有如下性质的二叉树：
     ⑴ 若它的左子树非空，则左子树上所有结点的值均小于根结点的值；
     ⑵ 若它的右子树非空，则右子树上所有结点的值均大于根结点的值；
     ⑶ 左、右子树本身又各是一棵二叉排序树。二叉排序树的性质： 
     按中序遍历二叉排序树，所得到的中序遍历序列是一个递增有序序列
*/
#include <iostream>
using namespace std; 

//树类前置声明
template<class T>
class Tree;

//树节点类
template<class T>
class Node
{
public:
	T key;
	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;
};

//树类
template<class T>
class Tree
{
public:
	//构造函数
	Tree();
	//析构函数
	~Tree();
	//前序遍历
	void Pre_order();
	//中序遍历
	void Mid_order();
	//后序遍历
	void Last_order();
	//(递归实现)查找树中键值为key的节点
	Node<T>* D_search(T key);
	//(非递归实现)查找树中键值为key的节点
	Node<T>* Serach(T key);
	//查找最小节点并返回值
	T min();
	//查找最大节点并返回值
	T max();
	// 找结点(x)的后继结点。即，查找"树中数据值大于该结点"的"最小结点"。
    Node<T>* successor(Node<T> *x);
    // 找结点(x)的前驱结点。即，查找"树中数据值小于该结点"的"最大结点"。
    Node<T>* predecessor(Node<T> *x);
	//插入节点
	void insert(T key);
	//删除节点
	void remove(T key);
	//销毁树
	void destory();
private:
	Node<T>* Troot;

	//前序遍历
	void Pre_order(Node<T>* root) const;
	//中序遍历
	void Mid_order(Node<T>* root) const;
	//后序遍历
	void Last_order(Node<T>* root) const;
	//(递归实现)查找树中键值为key的节点
	Node<T>* D_search(Node<T>* root,T key) const;
	//(非递归实现)查找树中键值为key的节点
	Node<T>* Serach(Node<T>* root,T key) const;
	//查找最小节点并返回节点
	Node<T>* min(Node<T>* root);
	//查找最大节点并返回节点
	Node<T>* max(Node<T>* root);
	//插入节点
	void insert(Node<T>* &root,Node<T>* node);
	//删除节点
	void remove(Node<T>* &root,Node<T>* node);
	//销毁树
	void destory(Node<T>* &root);

};

//构造函数
template<class T>
Tree<T>::Tree():Troot(NULL)	//参数列表形式
{
	Troot = NULL;
}

//析构函数
template<class T>
Tree<T>::~Tree()
{
	destory();
}

//前序遍历
template<class T>
void Tree<T>::Pre_order(Node<T>* root)const
{
	if(root != NULL)
	{
		cout<<root->key<<" ";
		Pre_order(root->left);
		Pre_order(root->right);
	}
}
template<class T>
void Tree<T>::Pre_order()
{
	Pre_order(Troot);
}

//中序遍历
template<class T>
void Tree<T>::Mid_order(Node<T>* root)const
{
	if(root)
	{
		Mid_order(root->left);
		cout<<root->key<<" ";
		Mid_order(root->right);
	}
}
template<class T>
void Tree<T>::Mid_order()
{
	Mid_order(Troot);
}

//后序遍历
template<class T>
void Tree<T>::Last_order(Node<T>* root)const
{
	if(root)
	{
		Last_order(root->left);
		Last_order(root->right);
		cout<<root->key<<" ";
	}
}
template<class T>
void Tree<T>::Last_order()
{
	Last_order(Troot);
}

//(递归实现)查找树中键值为key的节点
template<class T>
Node<T>* Tree<T>::D_search(Node<T>* root,T key)const
{
	if(root == NULL || root->key == key)
		return root;
	if(root->key > key)
		return D_search(root->left,key);
	if(root->key < key)
		return D_search(root->right,key);
}
template<class T>
Node<T>* Tree<T>::D_search(T key)
{
	D_search(Troot,key);
}

//(非递归实现)查找树中键值为key的节点
template<class T>
Node<T>* Tree<T>::Serach(Node<T>* root,T key)const
{
	if(root == NULL || root->key == key)
		return root;
	while(root->key != key)
	{
		if(root->key > key)
			root = root->left;
		if(root->key < key)
			root = root->right;
	}
	return root;
}
template<class T>
Node<T>* Tree<T>::Serach(T key)
{
	Serach(Troot,key);
}

//查找最小节点并返回节点
template<class T>
Node<T>* Tree<T>::min(Node<T>* root)
{
	if(root == NULL)
		return NULL;
	while(root->left)
	{
		root = root->left;
	}
	return root;
}
template<class T>
T Tree<T>::min()
{
	Node<T>* ret = min(Troot);
	if(ret)
		return ret->key;

	return NULL;
}

//查找最大节点并返回节点
template<class T>
Node<T>* Tree<T>::max(Node<T>* root)
{
	if(root == NULL)
		return NULL;

	while(root->right)
	{
		 root = root->right;
	}
	return root;
}
template<class T>
T Tree<T>::max()
{
	Node<T>* ret = max(Troot);
	if(ret)
		return ret->key;

	return NULL;
}

// 找结点(x)的后继结点。即，查找"树中数据值大于该结点"的"最小结点"。
template<class T>
Node<T>* Tree<T>::successor(Node<T> *x)
{
	//如果x有右孩子，则x的后继节点是以其右孩子为根的子树的最小节点
	if(x->right)
		return min(x->right);
	 // 如果x没有右孩子。则x有以下两种可能：
	 // (01) x是"一个左孩子"，则"x的后继结点"为 "它的父结点"。
    // (02) x是"一个右孩子"，则查找"x的最低的父结点，并且该父结点要具有左孩子"，找到的这个"最低的父结点"就是"x的后继结点"。
    Node<T>* y = x->parent;
    while((y!=NULL) && (x == y->right))
    {
    	x = y;
    	y = x->parent;
    }
    return y;
}

// 找结点(x)的前驱结点。即，查找"树中数据值小于该结点"的"最大结点"。
template<class T>
Node<T>* Tree<T>::predecessor(Node<T> *x)
{
	//如果x有左孩子，则x的前驱节点是以其左孩子为根的子树的最大值
	if(x->left)
		return max(x->left);
	//如果x没有左孩子，则x有一下两种可能
	//1.x是一个右孩子，则x的前驱节点是其父节点
	//2.x是一个左孩子，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
	Node<T>* y = x->parent;
	while((y!=NULL) && (x == y->left))
	{
		x = y;
		y = x->parent;
	}
	return y;
}


//插入节点 参考算法导论
template<class T>
void Tree<T>::insert(Node<T>* &root,Node<T>* node)
{
	Node<T>* y = NULL;
	Node<T>* x = root;

	 while (x != NULL)
    {
        y = x;
        if (node->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;
    if (y!=NULL)
    {
        if (node->key < y->key)
            y->left = node;
        else
            y->right = node;
    }
    else
        root = node;
}
template<class T>
void Tree<T>::insert(T key)
{
	Node<T>* node=new Node<T>;
	while(node == NULL)
	{
		node=new Node<T>;
	}
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	node->parent=NULL;
	insert(Troot,node);
}

/*删除节点
  有三种情况
  1.叶子节点：直接删除
  2.仅有左或右子树的节点：上移子树
  3.左右子树都有的节点：用删除节点的直接前驱或直接后继来替换当前节点，调整直接前驱或直接后继节点位置
*/
template<class T>
void Tree<T>::remove(Node<T>* &root,Node<T>* node)
{
	if(root == NULL || node == NULL)
		return;

	Node<T>* y = node->parent;
	Node<T>* tmp = NULL;
	//叶子节点
	if(node->left == NULL && node->right == NULL)
	{
		if(y->left == node)
			y->left = NULL;
		else
			y->right = NULL;
		delete node;
		node = NULL;
	}

	//仅有左或右子树的节点
	if(node->left == NULL)	//左空右不为空
	{
		Node<T>* next = min(node->right);
		node->key = next->key;
		if(next->parent->left == next)
			next->parent->left = NULL;
		else
			next->parent->right = NULL;
		delete next;
		next = NULL;
	}

	if(node->right == NULL)	//右空左不为空
	{
		Node<T>* pre = max(node->left);
		node->key = pre->key;
		if(pre->parent->left == pre)
			pre->parent->left = NULL;
		else
			pre->parent->right = NULL;
		delete pre;
		pre = NULL;
	}

	else	//左右都不为空 可以找前驱节点或者后继节点
	{
		Node<T>* pre = max(node->left);
		node->key = pre->key;
		if(pre->parent->left == pre)
			pre->parent->left = NULL;
		else
			pre->parent->right = NULL;
		delete pre;
		pre = NULL;
	}
}
template<class T>
void Tree<T>::remove(T key)
{
	Node<T>* tmp = Serach(Troot,key);
	if(tmp != NULL)
		remove(Troot,tmp);
}

//销毁树
template<class T>
void Tree<T>::destory(Node<T>*  &root)
{
	if(root == NULL)
		return;

	if(root->left != NULL)
		destory(root->left);
	if(root->right != NULL)
		destory(root->right);

	delete root;
	root = NULL;
}
template<class T>
void Tree<T>::destory()
{
	destory(Troot);
}


int main(int argc, char const *argv[])
{
	Tree<int> tree;
	tree.insert(22);
	tree.insert(12);
	tree.insert(56);
	tree.insert(2);
	tree.insert(17);
	tree.insert(34);
	tree.insert(27);
	tree.insert(45);
	tree.insert(77);
	tree.insert(60);
	tree.insert(80);
	// tree.Pre_order();
	// cout<<endl;
	tree.Mid_order();
	cout<<endl;
	// tree.Last_order();
	// cout<<endl;

	// cout<<tree.D_search(17)->key<<endl;
	// cout<<tree.Serach(2)->key<<endl;

	// int ret = tree.min();
	// cout<<ret<<endl;
	// ret = tree.max();
	// cout<<ret<<endl;

	
	//tree.insert(27);
	tree.remove(12);
	tree.Mid_order();
	cout<<endl;
	// tree.insert(13);
	// tree.insert(11);
	return 0;
}
