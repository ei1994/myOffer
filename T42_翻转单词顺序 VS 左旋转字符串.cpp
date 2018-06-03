/*
*
* 面试题42：翻转单词顺序 VS 左旋转字符串
*
*/

class Solution {
public:
    string ReverseSentence(string str) {
        if(str.size()==0)
            return str;
        reverse(str,0,str.size()-1);
        int start = 0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ')
            {
                reverse(str, start, i-1);
                start = i+1;
            }
        }
        reverse(str, start, str.size()-1);
        return str;
    }
private:
    void reverse(string& str,int start,int end)
    {
        while(start < end)
            swap(str[start++], str[end--]);
    }
};

//左旋转字符串
//

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(!str.size() || n<1 || n > str.size())
        {
            return str;
        }
        reverse(str,0,n-1);  //先单个翻转，再整体翻转
        reverse(str,n,str.size()-1);
        reverse(str,0,str.size()-1);
        return str;
    }
private:
    void reverse(string& str, int start,int end)
    {
        while(start<end)
            swap(str[start++], str[end--]);
    }
};
