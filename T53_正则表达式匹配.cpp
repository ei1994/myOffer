/*
 * 
 * 面试题53：正则表达式匹配
 * 题目：请实现一个函数来匹配包含'.'和'*'的正则表达式。模式中的字符'.'表示任何一个字符，
 * 而'*'表示它前面的字符可以出现任意次(含0次)，在本题中，匹配是指字符串的所有字符匹配整个模式。
 * 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
 *
 */
 class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(!str || !pattern)
            return false;
        return matchCore(str, pattern);
    }
    bool matchCore(char* str, char* pattern)
    {
        //都到字符串的尾部，匹配成功
        if(*str == '\0' && *pattern == '\0')
            return true;
        //字符串没结束，而模式已结束匹配失败
        if(*str != '\0' && *pattern == '\0')
            return false;
        //下一个字符'*'
        if(*(pattern + 1) == '*')
        {
            // 如果字符串和模式串相等，或者模式串是'.'，并且字符串没有到结尾，则继续匹配
            if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            {
                return matchCore(str+1, pattern+2) //匹配1次
                        || matchCore(str+1, pattern) //匹配n次
                        || matchCore(str,pattern+2);  //匹配0次
            }
            // 如果字符串和模式串不相等，则跳过当前模式串的字符和'*'，进入新一轮的匹配
            else
                return matchCore(str, pattern+2);
        }
        if(*str == *pattern || (*pattern == '.' && *str != '\0'))
            return matchCore(str+1, pattern+1);
        return false;
    }
};