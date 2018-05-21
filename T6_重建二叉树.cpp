/*
*
* 面试题6：重建二叉树
* 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
* 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
* 例如输入前序遍历序列{1,2,4,7,3,5,6,8}
* 和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*
*/

/*
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(!pre.size() || !vin.size() || pre.size() != vin.size())
            return nullptr;
        return reConstruct(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }
    TreeNode* reConstruct(vector<int> &pre, int preStart, int preEnd, vector<int> &vin, int vinStart, int vinEnd)
    {
        if(preStart > preEnd || vinStart > vinEnd)
            return nullptr;
        TreeNode* root = new TreeNode(pre[preStart]);
        for(int i=vinStart;i<=vinEnd;++i)
        {
            if(pre[preStart] == vin[i])
            {
                root->left = reConstruct(pre, preStart+1, preStart-vinStart+i, vin, vinStart, i-1);
                root->right = reConstruct(pre, preStart-vinStart+i+1, preEnd, vin, i+1, vinEnd);
                break;
            }
        }
        return root;
    }
};

