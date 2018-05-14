/*
*
* 面试题16：反转链表
* 题目：定义一个函数，输入链表的头结点，反转链表，并返回反转后链表的头结点
* 思路：pre cur next上个指针，pre记录前一个，cur为当前，
* next记录下一个（为了防止更改next时链表断开）
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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *pre=nullptr;
        ListNode *next=nullptr;
        while(pHead!=nullptr)
        {
            next=pHead->next;
            pHead->next=pre;
            pre=pHead;
            pHead=next;
        }
        return pre;
    }
};

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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *pre = nullptr;
        ListNode *nex = nullptr;
        ListNode *cur = pHead;
        while(cur != nullptr)
        {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};