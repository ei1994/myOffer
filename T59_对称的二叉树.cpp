/*
*
* 面试题59：对称的二叉树
* 请实现一个函数，用来判断一颗二叉树是不是对称的。
* 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
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
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == nullptr)
            return true;
        return isSymmetricalRun(pRoot, pRoot);
    }
    bool isSymmetricalRun(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == nullptr && root2 == nullptr)
            return true;
        if(root1 == nullptr || root2 ==nullptr)
            return false;
        if(root1->val != root2->val)
            return false;
        return isSymmetricalRun(root1->left, root2->right)
            && isSymmetricalRun(root1->right, root2->left);
    }
};
