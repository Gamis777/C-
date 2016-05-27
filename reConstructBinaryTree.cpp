/*输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，
则重建二叉树并返回。

Author:lp
date:2016-5-26

*/
#include <iostream>
#include <vector>
using namespace std;

//定义节点结构体
typedef struct Treenode
{
	int val;
	struct node* left;
	struct node* right;
}Treenode;

node* reConstructBinaryTree(vector<int> pre,vector<int> mid)
{
	int len = mid.size();	//求大小
	int i;
	node* root = new Treenode(pre[0]);	//根节点
	while( root == NULL )
	{
		root = new Treenode(pre[0]);
	}

	int num = 0;
	for(i=0;i<len;i++)
	{
		if(mid[i] == pre[0])
		{
			num = i;
			break;
		}
	}

	vector<int> pre_left,pre_right,mid_left,mid_right;

	//在中序数组中将根节点左边的数存入mid_left,右边的数存入mid_right
	//在前序数组中将1-(num-1)的数存入pre_left，将（num+1）-（len-1）的数存入pre_right
	for(i=0;i<num;i++)
	{
		pre_left.push_back(pre[i+1]);
		mid_left.push_back(mid[i]);
	}

	for(i=num+1;i<len;i++)
	{
		pre_right.push_back(pre[i]);
		mid_right.push_back(mid[i]);
	}

	//和shell排序的思想类似，取出前序和中序遍历根节点左边和右边的子树
    //递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
	root->left = reConstructBinaryTree(pre_left,mid_left);
	root->right = reConstructBinaryTree(pre_right,mid_right);

	return root;
}
int main(int argc, char const *argv[])
{
	vector<int> pre;
	vector<int> mid;
	reConstructBinaryTree(pre,mid);
	return 0;
}