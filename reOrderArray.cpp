/*输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

Author:lp
date:2016-5-31

思路：重新分配两个容器，分别存储之前的奇数和偶数 最后将之前的容器重新赋值

*/

#include <iostream>
#include <vector>

using namespace std;

void reOrderArray(vector<int> &Array)
{
	vector<int> v1,v2;
	int len = Array.size();
	int i;
	for(i=0;i<len;i++)
	{
		if(Array[i] % 2)
		{
			v1.push_back(Array[i]);
		}
		else
		{
			v2.push_back(Array[i]);
		}
	}

	int len1 = v1.size();
	int len2 = v2.size();

	for(i=0;i<len1;i++)
	{
		Array[i] = v1[i];
	}

	for(i=0;i<len2;i++)
	{
		Array[len1+i] = v2[i];
	}

	for(i=0;i<len;i++)
	{
		printf("%d\n",Array[i]);
	}
}

int main(int argc, char const *argv[])
{
	vector<int> Array;
	Array.push_back(1);	
	Array.push_back(2);	
	Array.push_back(3);	
	Array.push_back(4);	
	Array.push_back(5);	
	Array.push_back(6);	
	Array.push_back(7);	
	reOrderArray(Array);
	return 0;
}
