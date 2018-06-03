/*
*
* 面试题32：从1到n整数中1出现的次数
* 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
* 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
* 但是对于后面问题他就没辙了。ACMer希望你们帮帮他,
* 并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
*
*/
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<0)
            return 0;
        int count = 0;
        for(int i=1;i<=n;++i)
        {
            int val = i;
            while(val)
            {
                if(val%10 == 1)
                    ++count;
                val /= 10;
                
            }
        }
        return count;
        
        /*
        int count = 0;
        for(int i =1;i<=n;i*=10)
        {
            int a = n/i; 
            int b = n%i;
            count += (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
        }
        return count;
        */
    
    }
};