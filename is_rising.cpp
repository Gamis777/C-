/*用递归算法判断数组a[N]是否为一个递增数组
 思路：用一个数字记录当前最大的一个数，然后在用这个数和
 	   当前的这个数比较，如果小继续，大则返回
*/
#include <iostream>
using namespace std;

bool fun(int a[],int n)
{
	if(n == 1)
		return true;
	if(n == 2)
		return a[n-1]>=a[n-2];
	return fun(a,n-1) && a[n-1]>=a[n-2];
}
int main(int argc, char const *argv[])
{
	int a[5]={1,10,5,7,9};
	cout<<fun(a,5)<<endl;
	return 0;
}