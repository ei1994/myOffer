/*
*
* 面试题19：二叉树的镜像
* 操作给定的二叉树，将其变换为源二叉树的镜像
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot==nullptr)
            return;
        stack<TreeNode*> stackNode;
        stackNode.push(pRoot);
        while(!stackNode.empty())
        {
            TreeNode *node=stackNode.top();
            stackNode.pop();
            if(node->left!=nullptr || node->right!=nullptr)
            {
                TreeNode *temp=node->left;
                node->left=node->right;
                node->right=temp;
            }
            if(node->left)
                stackNode.push(node->left);
            if(node->right)
                stackNode.push(node->right);
            
            
        }
        
        
        /*if(pRoot==nullptr)
            return;
        TreeNode *temp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=temp;
        if(pRoot->left)
            Mirror(pRoot->left);
        if(pRoot->right)
            Mirror(pRoot->right);*/
    }
};