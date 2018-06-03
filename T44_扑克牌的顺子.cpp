
/*
*
* 面试题44：扑克牌的顺子
* 先把数字排序；其次统计数组中大小王的个数；
* 最后统计排序之后的数组中相邻数字之间的空缺总数。
* 如果空缺的空数小于或者等于大小王的个数，那么数组就是连续的，否则就是不连续的。
*
*/

class Solution {
public:
    bool IsContinuous( vector<int> number ) {
        if(number.empty())
            return false;
        sort(number.begin(), number.end());
		//计算数组中0的个数
        int numZero=0;
        for(int i=0;i<number.size();i++)
        {
            if(number[i]==0)
                numZero++;
        }
        int small=numZero;
        int big = small+1;
        int numGap = 0;
		//计算数组中空格个数
        while(big<number.size())
        {
            if(number[small]==number[big])
                return false;
            numGap += (number[big] - number[small] - 1);
            small = big;
            big++;
        }
        if(numGap <= numZero)
            return true;
        else
            return false;
    }
};
