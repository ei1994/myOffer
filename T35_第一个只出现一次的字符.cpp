/*
*
* 面试题35：第一个只出现一次的字符
* 在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
*
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(!str.size())
            return -1;
        map<char,int> item;//字符hash表，
        for(int i=0;i<str.size();i++)
            item[str[i]]++;
        for(int i=0;i<str.size();i++)
        {
            if(item[str[i]]==1)
                return i;
        }
        return -1;  //字符串中没有只出现一次的字符
    }
};