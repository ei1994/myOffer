/*
*
* 面试题34：丑数
* 把只包含因子2、3和5的数称作丑数（Ugly Number）。
* 例如6、8都是丑数，但14不是，因为它包含因子7。
* 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<7)  //小于7的都是丑数，直接返回
            return index;
        vector<int> result(index);
        int m2=0,m3=0,m5=0;  //对应的下标位置
        result[0]=1;
        for(int i=1;i<index;i++)
        {
            result[i]=min(result[m2]*2, min(result[m3]*3, result[m5]*5));
            //result中丑数是由小到大排序的，如果乘以系数还是小于数组最大的，
			//那肯定不是丑数,坐标相应加一
			while((result[m2]*2)<=result[i])  
                m2++;
            while((result[m3]*3)<=result[i])
                m3++;
            while((result[m5]*5)<=result[i])
                m5++;
        }
        return result[index-1];
    }
};