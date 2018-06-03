/*
*
* 面试题4：替换空格
* 请实现一个函数，将一个字符串中的空格替换成“%20”。
* 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*
*/
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str==NULL||length<=0)
            return;
        int oldnum=0,i=0;
        int replacenum=0;
        while(str[i]!='\0')
        {
            ++oldnum;
            if(str[i]==' ')
                ++replacenum;
            ++i;
        }
        int newnum=oldnum+2*replacenum;
        if(newnum>length)
            return;
        while(oldnum>=0 && oldnum<newnum)
        {
            if(str[oldnum]==' ')
            {
                str[newnum--]='0';
                str[newnum--]='2';
                str[newnum--]='%';
            }
            else
            {
                str[newnum]=str[oldnum];
                --newnum;
            }
            --oldnum;
        }
	}
};