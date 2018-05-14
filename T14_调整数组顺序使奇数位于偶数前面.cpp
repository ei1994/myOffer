/*
*
* 面试题14：调整数组顺序使奇数位于偶数前面
* 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
* 使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
* 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*
*/
// 冒泡排序方法，稳定排序
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.empty())
            return;
        bool isSwap = true;
        for(int i=0;(i<array.size()) && isSwap;++i)
        {
            isSwap = false;
            for(int j=array.size()-1;j>i;--j)
            {
                if((array[j-1] % 2 == 0) && (array[j] % 2 == 1))
                {
                    swap(array[j], array[j-1]);
                    isSwap = true;
                }
            }
        }
    }
};


//使用两次循环，一次找奇数，一次找偶数
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.empty())
            return ;
        vector<int> odd;
        for(int i=0; i<array.size();++i)
        {
            if(array[i]%2 == 1)
            {
                odd.push_back(array[i]);
            }
        }
        for(int i=0; i<array.size();++i)
        {
            if(array[i]%2 == 0)
            {
                odd.push_back(array[i]);
            }
        }
        array = odd;
    }
};
//使用迭代器
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> array_temp;
        vector<int>::iterator ib1;
        ib1=array.begin();
        for(;ib1!=array.end();)
        {
            if(*ib1%2==0)
            {
                array_temp.push_back(*ib1);
                ib1=array.erase(ib1);
            }
            else
                ib1++;
        }
        vector<int>::iterator ib2,ie2;
        ib2=array_temp.begin();
        ie2=array_temp.end();
        for(;ib2!=ie2;ib2++)
        {
            array.push_back(*ib2);
        }
        
    }
};