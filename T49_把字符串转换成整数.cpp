/*
*
* 面试题49：把字符串转换成整数
* 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
* 数值为0或者字符串不是一个合法的数值则返回0 
*
*/

class Solution {
public:
    enum Status {kValid = 0, kInvalid};
    int gStatus = kValid;
    
    int StrToInt(string str) {
        gStatus = kInvalid;
        long long result = 0;
        if(str.size() == 0)
            return 0;
        int idx = 0;
        bool minus = false;
        while(isspace(str[idx]))
            idx++;
        if(str[idx] == '+')
            idx++;
        else if(str[idx] == '-')
        {
            minus = true;
            idx++;
        }
        if(idx >= str.size())
            return 0;
        for(int i=idx; i<str.size(); i++)
        {
            if(str[i] >= '0' && str[i] <='9')
            {
                result = result *10 + (str[i] - '0');
            }
            else
                return 0;
        }
        result = minus ? -result : result;
        if(result > INT_MAX || result < INT_MIN)
            return 0;
        else 
        {
            gStatus = kValid;
            return result;
        }
    }
};
/*
int main()
{
	string a = "123";
	Solution res = Solution();
	int result = res.StrToInt(a);
	cout << result << "\n" << endl;

}
*/
