/*
*
* 面试题27：二叉搜索树与双向链表
* 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
* 要求不能创建任何新的结点，只能调整树中结点指针的指向。
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


    TreeNode* Convert(TreeNode* pRoot)
    {
		//递归
		//判断边界
        if(pRoot==nullptr)
            return pRoot;
        if(pRoot->left==nullptr && pRoot->right==nullptr)
            return pRoot;
		// 1.将左子树构造成双链表，并返回链表头节点
        TreeNode *left=Convert(pRoot->left);
		// 2.定位至左子树双链表最后一个节点
        TreeNode *p=left;
        while(p!=nullptr && p->right!=nullptr)
            p=p->right;
		// 3.如果左子树链表不为空的话，将当前root追加到左子树链表。
        if(left!=nullptr)
        {
            p->right=pRoot;
            pRoot->left=p;
        }
		// 4.将右子树构造成双链表，并返回链表头节点
        TreeNode *right=Convert(pRoot->right);
		// 5.如果右子树链表不为空的话，将该链表追加到root节点之后
        if(right!=nullptr)
        {
            pRoot->right=right;
            right->left=pRoot;
        }
		// 6.根据左子树链表是否为空确定返回的节点。
        return left!=nullptr?left:pRoot;
		
        /*
		if(pRoot==nullptr)
            return pRoot;
        stack<TreeNode*> st;
        TreeNode *p=pRoot;
        TreeNode *root,*pre;
        bool isFirst=true;
        while(p!=nullptr || !st.empty())
        {
            //循环遍历左子树
            while(p!=nullptr)
            {
                st.push(p);
                p=p->left;
            }
            p=st.top();
            st.pop();
            if(isFirst)
            {
                root=p;
                pre=root;
                isFirst=false;
            }
            else{
                p->left=pre;
                pre->right=p;
                pre=p;
            }
            p=p->right;
        }
        return root;
        */ 
    }
};