/*
*
* 面试题11：数值的整数次方
* 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*
*/
class Solution {
public:
    double Power(double base, int exponent) {
        if((base-0.0<0.0000001)&&(base-0.0>-0.0000001))
            return 0.0;
        int exp=exponent;
        if(exponent<0)
            exp=-exponent;
        double result=power_with_exp(base,exp);
        return exponent>0?result:1.0/result;
    
    }
    double power_with_exp(double base,int exponent){
        if(exponent==0)
            return 1;
        if(exponent==1)
            return base;
        double result=power_with_exp(base,exponent>>1);
        result*=result;
        if((exponent & 1) ==1)
            result*=base;
        return result;
    }
};