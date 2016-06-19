/*输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。
假设输入的数组的任意两个数字都互不相同。
 Author:lp
 date:2016-6-14

 思路：可以利用递归的思想。后序遍历的最后一个元素必定是根节点。可以将根节点之前的元素分成两半。
 		大于根节点的和小于根节点的元素。他们必定也满足后序遍历数组的特点。所以可以递归...
*/

#include <iostream>
using namespace std;

//将数组分半并递归
bool part(int a[],int left,int right)
{
	if(left >= right)
		return true;

	int i = right-1;
	while(i>left && a[i] > a[right])
		i--;
	int j;
	for(j=i-1;j>=left;j--)
	{
		if(a[j] > a[right])
			return false;
	}
	return part(a,left,i-1) && part(a,i,right);
}

bool VerifySequenceOfBST(int a[],int len)
{
	if(len == 0)
		return false;
	return part(a,0,len-1);
}
int main(int argc, char const *argv[])
{
	int a[8] = {2,9,5,17,15,19,18,12};
	cout<<VerifySequenceOfBST(a,8)<<endl;
	return 0;
}