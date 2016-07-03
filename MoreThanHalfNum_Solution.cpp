/*数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0

  要求时间复杂度较低

  Author:lp
  date:2016/7/3

  思路：时间复杂度为O(n)
*/
#include <iostream>
#include <vector>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> per)
{
	int tmp,count = 0;
	int len = per.size();
	if(len == 0)
		return tmp;
	int i;
	for(i=0;i<len;i++)	//求出如果存在一个数字的次数大于数组长度 则tmp等于该数字
	{
		if(per[i] == tmp)
			count++;
		else if(count > 0)
			count--;
		else
		{
			tmp = per[i];
			count = 1;
		}
	}
	//验证
	count = 0;
	for(i=0;i<len;i++)
	{
		if(per[i] == tmp)
			count++;
	}
	return count>(len/2)?tmp:0;
}
int main(int argc, char const *argv[])
{
	vector<int> per;
	per.push_back(1);
	per.push_back(2);
	per.push_back(3);
	per.push_back(2);
	per.push_back(2);
	per.push_back(2);
	per.push_back(5);
	per.push_back(4);
	per.push_back(2);
	int res = MoreThanHalfNum_Solution(per);
	cout<<res<<endl;
	return 0;
}