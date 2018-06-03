/*
*
* 面试题补7：按之字形顺序打印二叉树
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if(pRoot == nullptr)
            return result;
        stack<TreeNode*> st1,st2;
        st1.push(pRoot);
        while(!st1.empty() || !st2.empty())
        {
            if(!st1.empty())
            {
                vector<int> v;
                while(!st1.empty())
                {
                    TreeNode *curNode = st1.top();
                    st1.pop();
                    v.push_back(curNode->val);
                    if(curNode->left != nullptr)
                        st2.push(curNode->left);
                    if(curNode->right != nullptr)
                        st2.push(curNode->right);
                }
                result.push_back(v);
            }
            if(!st2.empty())
            {
                vector<int> v;
                while(!st2.empty())
                {
                    TreeNode *curNode = st2.top();
                    st2.pop();
                    v.push_back(curNode->val);
                    if(curNode->right != nullptr)
                        st1.push(curNode->right);
                    if(curNode->left != nullptr)
                        st1.push(curNode->left);
                }
                result.push_back(v);
            }
        }
        return result;
    }
};