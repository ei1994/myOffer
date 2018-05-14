/*
*
* 面试题3：二维数组的查找
* 在一个二维数组中，每一行都按照从左到右递增的顺序排序，
* 每一列都按照从上到下递增的顺序排序。
* 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
* 例如:
* 1   2    8     9
* 2   4    9    12
* 4   7    10  13
* 6   8    11  15
*
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        int row = array.size();
        int col = array[0].size();
        int i = 0;
        int j = col - 1;
        while(i < row && j >= 0)
        {
            if(target == array[i][j])
            {
                return true;
            }
            else if(target < array[i][j])
            {
                --j;
            }
            else
                ++i;
        }
        return false;
    }
};
