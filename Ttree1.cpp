/*树是一个非线性结构 有且只有一个根节点 
	节点度：含有子节点的数目
*/
#include <iostream>
#include <queue>
using namespace std;
//树节点
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

//创建树
Node* create_tree()
{
	Node* root = NULL;
	int data;
	scanf("%d",&data);
	if(data == -1)
		return NULL;
	else
	{
		root = new Node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		root->left = create_tree();
		root->right = create_tree();
	}
	return root;
}

//前序遍历
void pre_order(Node* root)
{
	if(root)
	{
		cout<<root->data<<" ";
		pre_order(root->left);
		pre_order(root->right);
	}
}

//中序遍历
void in_order(Node* root)
{
	if(root)
	{
		in_order(root->left);
		cout<<root->data<<" ";
		in_order(root->right);
	}
}

//后序遍历
void last_order(Node* root)
{
	if(root)
	{
		last_order(root->left);
		last_order(root->right);
		cout<<root->data<<" ";
	}
}


//层次遍历需要写一个队列
queue<int> level_order(Node* root)
{
	queue<Node*> node;
	queue<int> val;
	if(root == NULL)
		return val;
	node.push(root);
	while(!node.empty())
	{
		if(node.front()->left != NULL)
			node.push(node.front()->left);
		if(node.front()->right != NULL)
			node.push(node.front()->right);
		val.push(node.front()->data);
		node.pop();
	}
	return val;
}
int main(int argc, char const *argv[])
{
	Node* root = create_tree();
	pre_order(root);
	cout<<endl;

	in_order(root);
	cout<<endl;
	
	last_order(root);
	cout<<endl;

	queue<int> res = level_order(root);
	while(!res.empty())
	{
		cout<<res.front()<<" ";
		res.pop();
	}
	cout<<endl;
	return 0;
}
