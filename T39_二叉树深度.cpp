/*
*
* 面试题39：二叉树的深度
* 输入一棵二叉树，求该树的深度。
* 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==nullptr)
            return 0;
        int left=TreeDepth(pRoot->left);
        int right=TreeDepth(pRoot->right);
        return left>right?left+1:right+1;
    }
};

/* 判断是否是平衡二叉树 */
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth=0;
        return isBalanced(pRoot,depth);
    }
private:
    bool isBalanced(TreeNode *pRoot,int &depth)
    {
        if(pRoot==nullptr)
        {
            depth=0;
            return true;
        }
        int left=0,right=0;
        if(isBalanced(pRoot->left,left) && isBalanced(pRoot->right,right))
        {
            int dif=abs(left-right);
            if(dif<=1)
            {
                depth=max(left,right)+1;
                return true;
            }
        }
        return false;
    }
};

