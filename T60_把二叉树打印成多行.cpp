/*
*
* 面试题60：把二叉树打印成多行
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
            queue<TreeNode*> qt;
            qt.push(pRoot);
            while(!qt.empty())
            {
                vector<int> v;
                int num = qt.size();
                int i=0;
                while(i<num)
                {
                    TreeNode *curNode = qt.front();
                    qt.pop();
                    v.push_back(curNode->val);
                    if(curNode->left)
                        qt.push(curNode->left);
                    if(curNode->right)
                        qt.push(curNode->right);
                    i++;
                }
                result.push_back(v);
            }
            
            return result;
        }
    
};