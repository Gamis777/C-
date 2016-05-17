#include <iostream>
/*在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。*/
class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        int row=0;
        int col=array[0].size()-1;
        while(row<=array.size()-1 && col>=0)
            {
            if(array[row][col]==target)
                return true;
            else if(array[row][col]>target)
                col--;
            else
                row++;
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
	
	return 0;
}