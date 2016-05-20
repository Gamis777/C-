/*将一组整型数组进行冒泡排序 分别有升序和降序 用排序谓词实现*/
#include <iostream>
using namespace std;
#define N 7

//排序谓词
bool CMP(int a,int b)
{
	return a<b;	//降序
	//return a>b;	升序
}

int main(int argc, char const *argv[])
{
	int A[N];
	int i;
	int data;
	for(i=0;i<N;i++)
	{
		scanf("%d",&data);
		A[i]=data;
	}

	int j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N-i-1;j++)
		{
			if(CMP(A[j],A[j+1]))
			{
				int tmp=A[j];
				A[j]=A[j+1];
				A[j+1]=tmp;
			}
		}
	}

	for(i=0;i<N;i++)
	{
		cout<<A[i]<<'\t';
	}
	cout<<endl;
	return 0;
}
