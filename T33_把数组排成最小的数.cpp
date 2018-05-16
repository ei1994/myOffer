/*
*
* 面试题33：把数组排成最小的数
* 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
* 打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
* 则打印出这三个数字能排成的最小数字为321323。
*
*/

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string result;
        if(numbers.empty())
            return result;
        vector<string> strNum;
        for(int i=0;i<numbers.size();++i)
        {
            //stringstream ss;
            //ss << numbers[i];
            //strNum.push_back(ss.str());
            strNum.push_back(to_string(numbers[i]));
        }
        sort(strNum.begin(),strNum.end(),compare);
        for(int i=0;i<strNum.size();++i)
        {
            result += strNum[i];
        }
        return result;
    }
    static bool compare(const string &a, const string &b)
    {
        string s1 = a + b;
        string s2 = b + a;
        return s1 < s2;
    }
};