/*
*
* 面试题25：二叉树中和为某一值的路径
* 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
* 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==nullptr)
            return result;
        preorder(root,expectNumber);
        return result;
    }
    void preorder(TreeNode* root,int expectNumber)
    {
        if(root==nullptr)
            return;
        temp.push_back(root->val);
        expectNumber -= root->val;
        if(root->left==nullptr && root->right==nullptr && expectNumber==0)
            result.push_back(temp);
        else{
            preorder(root->left,expectNumber);
            preorder(root->right,expectNumber);
        }
        temp.pop_back();
    }
    
private:
    vector<vector<int>> result;
    vector<int> temp;
};