/*
*
* 面试题17：合并两个排序的链表 
* 输入两个单调递增的链表，输出两个链表合成后的链表，
* 当然我们需要合成后的链表满足单调不减规则。
*
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==nullptr)
            return pHead2;
        if(pHead2==nullptr)
            return pHead1;
        ListNode *root;
        if(pHead1->val < pHead2->val)
        {
            root=pHead1;
            root->next=Merge(pHead1->next,pHead2);
        }
        else
        {
            root=pHead2;
            root->next=Merge(pHead1,pHead2->next);
        }
        return root;
        
        
        
        
        /*
        ListNode *merge=nullptr;
        ListNode *cur=nullptr;
        while(pHead1!=nullptr && pHead2!=nullptr)
        {
            if(pHead1->val < pHead2->val)
            {
                if(merge==nullptr)
                    merge=cur=pHead1;
                else
                {
                    cur->next=pHead1;
                    cur=cur->next;
                }
                pHead1=pHead1->next;
            }
            else
            {
                if(merge==nullptr)
                    merge=cur=pHead2;
                else 
                {
                    cur->next=pHead2;
                    cur=cur->next;
                }
                pHead2=pHead2->next;
            }
        }
        if(pHead1!=nullptr)
            cur->next=pHead1;
        if(pHead2!=nullptr)
            cur->next=pHead2;
        return merge;*/
    }
};