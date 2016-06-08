/*输入两颗二叉树A，B，判断B是不是A的子结构。
 Author:lp
 date:2016-6-7

 第一个思路：第一步在树A中找到和B的根节点的值一样的结点R；
		第二步再判断树A中以R为根结点的子树是不是包含和树B一样的结构。

第一步在树A中查找与根结点的值一样的结点，这实际上就是树的遍历。递归调用HasSubTree遍历二叉树A。
如果发现某一结点的值和树B的头结点的值相同，则调用DoesTreeHavaTree2，做第二步判断。
第二步是判断树A中以R为根结点的子树是不是和树B具有相同的结构。

	第二个思路：将其两个的前序遍历转换为字符串类型 如果其中一个是另一个的字串，说明也是子树
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
//定义树节点
typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//初始化树
TreeNode* init_tree()
{
	TreeNode* root = NULL;
	int data;
	scanf("%d",&data);
	if(data == -1)
		return NULL;
	else
	{
		root = (TreeNode*)malloc(1*sizeof(TreeNode));
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		root->left = init_tree();
		root->right = init_tree();
	}
	return root;
}

void Pre_order(TreeNode* root)
{
	if(root)
	{
		//printf("%d ",root->data);
		cout<<root->data<<" ";
		Pre_order(root->left);
		Pre_order(root->right);
	}
}


//方法1
bool DoseHasSubtree(TreeNode* root1,TreeNode* root2)
{
	if(root2 == NULL)
		return true;
	if(root1 == NULL)
		return false;
	if(root1->data != root2->data)
		return false;

	return DoseHasSubtree(root1->left,root2->left) && DoseHasSubtree(root1->right,root2->right);
}

int HasSubtree(TreeNode* root1,TreeNode* root2)
{
	int flag = false;
	if(root1->data == root2->data)
		flag = DoseHasSubtree(root1,root2);
	if(!flag)
		flag = HasSubtree(root1->left,root2);
	if(!flag)
		flag = HasSubtree(root1->right,root2);

	return flag;
}


//方法2
void get_tree_string(TreeNode* root,char str[],int count)
{
	if(root)
	{
		str[count] = root->data + '0';
		// count++;
		get_tree_string(root->left,str,count);
		get_tree_string(root->right,str,count);
	}
}

int main(int argc, char const *argv[])
{
	TreeNode* root1 = init_tree();
	Pre_order(root1);
	//printf("\n");
	cout<<endl;

	TreeNode* root2 = init_tree();
	Pre_order(root2);
	//printf("\n");
	cout<<endl;

	//cout<<DoseHasSubtree(root1,root2)<<endl;
	//printf("%d\n",ret);
	char str[20] = {0};
	int count = 0;
	get_tree_string(root1,str,count);
	printf("str=%s\n",str);
	return 0;
}
