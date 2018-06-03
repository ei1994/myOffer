/*
*
* 面试题45：圆圈中的最后剩下的数字
* 0,1,...,n-1这n个数字排成一个圆圈，从数字0开始，
* 每次从这个圆圈中删除第m个数字，求出这个圆圈里最后一个数字。
*
*/

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1 || m<1)
            return -1;
        int *array = new int[n];
        int i = -1;
        int step = 0;
        int count = n;
        while(count > 0)
        {
            i++;
            if(i == n)
                i = 0;
            if(array[i] == -1)
                continue;
            step++;
            if(step == m)
            {
                step = 0;
                array[i] = -1;
                count--;
            }
        }
        return i;
        
    }
};

//利用公式递推计算。
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1 || m<1)
            return -1;
        int last = 0;
        for(int i=2;i<=n;i++)
        {
            last = (last + m)%i;
        }
        return last;
    }
};
