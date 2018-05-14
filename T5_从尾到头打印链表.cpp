/*
*
* 面试题5：从尾到头打印链表
* 输入一个链表，从尾到头打印链表每个节点的值。
*
*/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> vi;
        while(head != nullptr)
        {
            vi.push(head->val);
            head = head->next;
        }
        vector<int> result;
        while(!vi.empty())
        {
            result.push_back(vi.top());
            vi.pop();
        }
        return result;
    }
};