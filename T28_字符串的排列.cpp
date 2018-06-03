/*
*
* 面试题28：字符串的排列
* 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
* 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*
*/
class Solution {
public:
    vector<string> result;
    void premutation(string str, int idx)
    {
        if(idx==str.size()){
            result.push_back(str);
            return;
        }
        for(int i=idx;i<str.size();i++)
        {
            if(i!=idx && str[idx]==str[i])
                continue;
            swap(str[idx],str[i]);
            premutation(str,idx+1);
            swap(str[idx],str[i]);
        }
    }
    vector<string> Permutation(string str) {
        if(str.empty())
            return result;
        premutation(str,0);
        sort(result.begin(),result.end());
        return result;
    }
};