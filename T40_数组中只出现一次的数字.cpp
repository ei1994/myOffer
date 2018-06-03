/*
*
* 面试题40：数组中只出现一次的数字
* 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
* 请写程序找出这两个只出现一次的数字。
*
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()<2)
            return;
        int resultOR = 0;
        for(int i=0;i<data.size();i++)
        {
            resultOR ^= data[i];
        }
        unsigned int indexBit = findFirstOne(resultOR);
        *num1 = *num2 = 0;
        for(int j=0;j<data.size();j++)
        {
            if(isBit1(data[j],indexBit))
            {
                *num1 ^= data[j];
            }
            else
                *num2 ^= data[j];
        }
    }
private:
    unsigned int findFirstOne(int num)
    {
        int indexBit=0;
        while(((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
        {
            num = num >> 1;
            indexBit++;
        }
        return indexBit;
    }
    bool isBit1(int num,unsigned int indexBit)
    {
        num = num >> indexBit;
        return (num & 1);
    }
};