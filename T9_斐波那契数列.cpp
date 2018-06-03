/*
*
* 面试题9：斐波那契数列
* f(n) = f(n-1)+f(n-2)
*
*/
class Solution {
public:
    int Fibonacci(int n) {
        if(n==0)
            return 0;
        else if(n==1)
            return 1;
        int last=1;
        int last_last=0;
        int result=0;
        for(int i=2;i<=n;i++)
        {
            result=last+last_last;
            last_last=last;
            last=result;
        }
        return result;

    }
};

//跳台阶

class Solution {
public:
    int jumpFloor(int number) {
        if(number==0)
            return 0;
        else if(number==1)
            return 1;
        else if(number==2)
            return 2;
        int result=0;
        int last=2;
        int last_last=1;
        for(int i=3;i<=number;i++)
        {
            result=last+last_last;
            last_last=last;
            last=result;
        }
        return result;
    }
};
//变态跳台阶
class Solution {
public:
    int jumpFloorII(int number) {
        /*
        if(number==0)
            return 0;
        else if(number==1)
            return 1;
        else if(number==2)
            return 2;
        else
            //return 2*jumpFloorII(number-1);
            */
        return 1 << (number-1);
    }
};




