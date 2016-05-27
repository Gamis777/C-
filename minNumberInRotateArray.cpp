/*把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
#include <iostream>
#include <vector>
using namespace std;

int FindMinRotateArray(vector<int> RotateArray)
{
	int size = RotateArray.size();	//求出容器大小
	if(size == 0)
		return 0;
	else
	{
		int i;
		int min = RotateArray[0];
		for(i=1;i<size;i++)
		{
			if(min > RotateArray[i])
			{
				min = RotateArray[i];
			}
		}
		return min;
	}
}

int main(int argc, char const *argv[])
{
	vector<int> RotateArray;
	RotateArray.push_back(3);
	RotateArray.push_back(4);
	RotateArray.push_back(5);
	RotateArray.push_back(1);
	RotateArray.push_back(2);
	cout<<FindMinRotateArray(RotateArray)<<endl;
	return 0;
}
