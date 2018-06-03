
//和为s的两个数字
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> result;
        if(array.size()<2)
            return result;
        int left=0;
        int right=array.size()-1;
        while(left<right)
        {
            int addSum = array[left]+array[right];
            if(addSum > sum)
                right--;
            else if(addSum < sum)
                left++;
            else 
            {
                result.push_back(array[left]);
                result.push_back(array[right]);
                break;
            }
        }
        return result;
    }
};

/*
*
* 面试题41：和为s的两个数字VS和为s的连续正数序列
*
还可以用公式计算和

*/


class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        if(sum<3)
            return result;
        int left = 1;
        int right = 2;
        int addSum = 3;
        while(left < ((sum+1)/2))
        {
            if(addSum < sum)
            {
                right += 1;
                addSum += right;
            }
            else if (addSum > sum)
            {
                addSum -= left;
                left += 1;
            }
            else
            {
                vector<int> temp;
                for(int i=left;i<=right; i++)
                    temp.push_back(i);
                result.push_back(temp);
                right += 1;
                addSum += right;
            }
        }
        return result;
    }
};

//用求和公式计算
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        if(sum<3)
            return result;
        int left = 1;
        int right = 2;
        int addSum = 3;
        while(left < ((sum+1)/2))
        {
            addSum = (left + right)*(right - left + 1)/2;
            if(addSum < sum)
            {
                right++;
            }
            else if (addSum > sum)
            {
                left++;
            }
            else
            {
                vector<int> temp;
                for(int i=left;i<=right; i++)
                    temp.push_back(i);
                result.push_back(temp);
                right++;
            }
        }
        
        return result;
    }
};