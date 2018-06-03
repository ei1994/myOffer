/*
*
* 面试题62：序列化二叉树
* 请实现两个函数，分别用来序列化和反序列化二叉树
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
    char* Serialize(TreeNode *root) {    
        if(!root)
            return nullptr;
        string str;
        SerializeCore(root, str);
        char* result = new char[str.size()+1];
        strcpy(result, str.c_str());
        return result;
    }
    void SerializeCore(TreeNode* root, string &str)
    {
        if(!root)
        {
            str.push_back('#');
            return ;
        }
        string s = to_string(root->val);
        str += s;
        str += ',';
        SerializeCore(root->left, str);
        SerializeCore(root->right, str);
    }
    TreeNode* Deserialize(char *str) {
        if(str == nullptr)
            return nullptr;
        return DeserializeCore(str);
    }
    TreeNode* DeserializeCore(char* &str)
    {
        if(*str == '#')
        {
            str++;
            return nullptr;
        }
        int num = 0;
        while(*str != ',')
        {
            num = num*10 + *str-'0';
            str++;
        }
        str++;
        TreeNode *root = new TreeNode(num);
        root->left = DeserializeCore(str);
        root->right = DeserializeCore(str);
        return root;
    }
};