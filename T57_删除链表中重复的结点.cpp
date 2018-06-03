/*
*
* 面试题补4：删除链表中重复的结点
*
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode *curNode = pHead;
        ListNode *preNode = nullptr;
        ListNode *nexNode = nullptr;
        while(curNode != nullptr)
        {
            if(curNode->next != nullptr && curNode->val == curNode->next->val)
            {
                nexNode = curNode->next;
                while(nexNode->next != nullptr && curNode->val == nexNode->next->val)
                {
                    nexNode = nexNode->next;
                }
                if(curNode == pHead)
                {
                    pHead = nexNode->next;
                }
                else{
                    preNode->next = nexNode->next;  //始终与下一个没有重复的结点连接在一起
                }
                curNode = nexNode->next;
                
            }
            else{
                preNode = curNode;
                curNode = curNode->next;
            }
        }
        return pHead;
    }
};