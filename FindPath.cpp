/*输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
  路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

  Author:lp
  date:2016/6/19

  思路：vector<vector<int> >listpath记录所有的路径，vector<int> path记录某一条路径。
  		当前节点的值与num相等并且当前节点为叶子节点时，将path加入到pathlist中，并将
  		path最后最后一个节点删除。否则利用递归进行左右节点判断，不满足时也要将刚加入
  		的节点删除。

*/
#include <iostream>
#include <vector>
using namespace std;

//创建树节点
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

void Print_tree(Node* root)
{
	if(root)
	{
		cout<<root->data<<" ";
		Print_tree(root->left);
		Print_tree(root->right);
	}
}

void Treepath(Node* root,int num,vector<int>& path,vector<vector<int> >& pathlist)
{
	if(root == NULL)
		return;
	bool isleaf = root->left == NULL && root->right == NULL;
	path.push_back(root->data);
	if(root->data == num && isleaf)
	{
		pathlist.push_back(path);
		path.pop_back();
	}
	else
	{
		Treepath(root->left,num-(root->data),path,pathlist);
		Treepath(root->right,num-(root->data),path,pathlist);
		path.pop_back();
	}
}
vector<vector<int> > FindPath(Node* root,int num)
{
	vector<int> path;
	vector<vector<int> > pathlist;
	if(root == NULL)
		return pathlist;
	Treepath(root,num,path,pathlist);
	return pathlist;
}

int main(int argc, char const *argv[])
{
	Node* root = create_tree();
	Print_tree(root);
	cout<<endl;
	int num;
	scanf("%d",&num);
	FindPath(root,num);
	return 0;
}
