/*
*
* 面试题补3：链表中环的入口结点
* 一个链表中包含环，请找出该链表的环的入口结点。
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == nullptr || pHead->next ==nullptr)
            return nullptr;
        ListNode *slow = pHead;
        ListNode *fast = pHead->next->next;
        
        //在环中相遇,快走两步，慢走一步
        while(slow != fast)
        {
            if(fast->next != nullptr && fast->next->next != nullptr )
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            else
                return nullptr;
        }
        
        int numLoop = 1;
        slow = slow->next;
		//计算环的节点数
        while(slow!=fast)
        {
            numLoop++;
            slow = slow->next;
        }
		//寻找环的入口，快的先走环的节点数
        fast = pHead;
        for(int i=0;i<numLoop;i++)
        {
            fast = fast->next;
        }
        
        slow = pHead;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

};