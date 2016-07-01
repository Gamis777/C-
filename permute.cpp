/*输入一个字符串,按字典序打印出该字符串中字符的所有排列。
  例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 
  结果请按字母顺序输出

  Author:lp
  date:2016/7/1

  思路：
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void swap(char& a,char& b)	//交换两个字符
{
	a = a^b;
	b = a^b;
	a = a^b;
}


void Permutation(string str)
{
	//字典序法找到全排列
	int len = str.size();
	vector<string> result;
	if(len == 0)
		return;

	result.push_back(str);
	int i;
	int index2,index1;
	while(1)
	{
		//从这个序列中从右至左找第一个左邻小于右邻的字符
		index1 = -1;
		for(i=len;i>=1;i--)
		{
			if(str[i] > str[i-1])
			{
				index1 = i-1;
				break;
			}
		}

		if(index1 == -1)
			break;

		//从这个序列中从右至左找第一个大于str[index1]的字符
		for(i=len;i>=1;i--)
		{
			if(str[i] > str[index1])
			{
				 index2 = i;
				 break;
			}
		}

		swap(str[index1],str[index2]);	//将index1与index2所在元素交换
		//将index1+1至最后一个元素从小到大排序
		sort(str.begin()+index1+1,str.end());  //默认是升序的
        result.push_back(str);
	}
	
	len = result.size();
	for(i=0;i<len;i++)
	{
		cout<<result[i]<<endl;
	}
}

int main(int argc, char const *argv[])
{
	string str = "abcd";
	Permutation(str);
	
	return 0;
} 