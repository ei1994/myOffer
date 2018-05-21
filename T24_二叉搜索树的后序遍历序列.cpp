/*
*
* 面试题24：二叉搜索树的后序遍历序列
* 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
* 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
        return isLastOrder(sequence,0,sequence.size()-1);
    }
    bool isLastOrder(const vector<int> seq,int start,int end)
    {
        if(start>=end)
            return true;
        int root=seq[end];
        int i=start;
        for(;i<end;i++)
        {
            if(seq[i]>root)
                break;
        }
        for(int j=i;j<end;j++)
        {
            if(seq[j]<root)
                return false;
        }
        return isLastOrder(seq,start,i-1) && isLastOrder(seq,i,end-1);
    }
};