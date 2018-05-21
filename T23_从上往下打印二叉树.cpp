/*
*
* 面试题23：从上往下打印二叉树
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;
        if(root==nullptr)
            return result;
        
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode *node=que.front();
            que.pop();
            result.push_back(node->val);
            if(node->left != nullptr)
                que.push(node->left);
            if(node->right != nullptr)
                que.push(node->right);
        }
        return result;
        
        

    }
};