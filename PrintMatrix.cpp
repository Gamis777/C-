/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
  如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
  则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

  Author:lp
  date:2016-6-7

  思路：
*/

#include <iostream>
using namespace std;

void PrintMatrix(int matrix[4][4],int row,int col)
{
	int row0 = 0;
	int col0 = 0;
	if(matrix == NULL)
		return ;

	while(row0 < row && col0 < col)
	{
		int i;
		for(i=col0;i<col;i++)
		{
			printf("%d,",matrix[row0][i]);
		}

		for(i=row0+1;i<row;i++)
		{
			printf("%d,",matrix[i][col-1]);
		}

		if(row0 != row-1)
		{
			for(i=col-2;i>=col0;i--)
			{
				printf("%d,",matrix[row-1][i]);
			}
		}

		if(col0 != col-1)
		{
			for(i=row-2;i>row0;i--)
			{
				printf("%d,",matrix[i][col0]);
			}
		}

		col0++;
		row0++;
		col--;
		row--;
	}
}

int main(int argc, char const *argv[])
{
	int matrix[4][4];
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			matrix[i][j] = i*4+j+1;
		}
	}

	PrintMatrix(matrix,4,4);
	return 0;
}