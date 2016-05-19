/*有一个整数数组，请你根据快速排序的思路，找出数组中第K大的数。
给定一个整数数组a,同时给定它的大小n和要找的K(K在1到n之间)，请返回第K大的数，保证答案存在*/
#include <iostream>
using namespace std;

int partarray(int a[],int left,int right)
{
	int tmp;
	tmp=a[left];
	while(left<right)
	{
		while(a[left]<a[right] && left<right)
		{
			right--;
		}
		if(left<right)
		{
			a[left]=a[right];
			left++;
		}
		while(a[left]<tmp && left<right)
		{
			left++;
		}
		if(left<right)
		{
			a[right]=a[left];
			right--;
		}
	}
	a[left]=tmp;
	return left;
}

void sort(int a[],int left,int right)
{
	if(left<right)
	{
		int mid=partarray(a,left,right);
		sort(a,left,mid-1);
		sort(a,mid+1,right);
	}
}

void findKth(int a[],int left,int right,int K)
{
	sort(a,0,right-1);
	cout<<a[right+1-K]<<endl;
}
int main(int argc, char const *argv[])
{
	int a[]={1,3,5,2,2,7,9};
	findKth(a,0,6,3);
	return 0;
}