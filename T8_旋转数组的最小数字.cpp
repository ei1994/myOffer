/*
*
* 面试题8：旋转数组的最小数字
* 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
* 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
* 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
* NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*
*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        int low = 0;
        int high = rotateArray.size() - 1;
        if(rotateArray[low] < rotateArray[high])
            return rotateArray[0];
        while(low < high)
        {
            int mid = (high + low)/2;
            if(rotateArray[mid] > rotateArray[high])
                low = mid +1;
            else if(rotateArray[mid] < rotateArray[high])
                high = mid;
            else
                high--;//如果相等就顺序查找
        }
        return rotateArray[high];
    }
};
