/*从上往下打印出二叉树的每个节点，同层节点从左至右打印。
  Author:lp
  date:2016-6-12

  思路：利用两个数组或者容器v1 v2.
  		v1存储树节点 v2存储节点值
  		首先将根节点存进v1 读取v1的第一个元素。判断该元素的左右节点是否存在
  		存在则存入v1中，然后将第一个元素的值存入v2
  		循环读取v1的下一个元素，继续上面的操作。直至将v1读完
*/
#include <iostream>
#include <vector>
using namespace std;
//定义树节点
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

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

//层次遍历
vector<int> LevelPrint(Node* root)
{
	vector<Node*> node_V;
	vector<int> res_V;
	if(root == NULL)
		return res_V;
	else
	{
		node_V.push_back(root);
		int p = 0;
		while(p < node_V.size())
		{
			Node* tmp =  node_V[p++];
			if(tmp->left)
				node_V.push_back(tmp->left);
			if(tmp->right)
				node_V.push_back(tmp->right);
			res_V.push_back(tmp->data);
		}
	}
	return res_V;
}
int main(int argc, char const *argv[])
{
	Node* root = create_tree();
	//Print_tree(root);
	vector<int> res = LevelPrint(root);
	int size = res.size();
	int i;
	for(i=0;i<size;i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}