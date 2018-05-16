/*
*
* 面试题37：两个链表的第一个公共结点
*
方法一：

我们可以把两个链表拼接起来，一个pHead1在前pHead2在后，一个pHead2在前pHead1在后。
这样，生成了两个相同长度的链表，那么我们只要同时遍历这两个表，就一定能找到公共结点
。时间复杂度O(m+n)，空间复杂度O(m+n)。

方法二：

我们也可以先让把长的链表的头砍掉，让两个链表长度相同，
这样，同时遍历也能找到公共结点。
此时，时间复杂度O(m+n)，空间复杂度为O(MAX(m,n))。
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
    unsigned int getLen(ListNode* pHead)
    {
        unsigned int length=0;
        while(pHead)
        {
            length+=1;
            pHead=pHead->next;
        }
        return length;
    }
    
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==nullptr || pHead2==nullptr)
            return nullptr;
        unsigned int len1=getLen(pHead1);//先找出长链表和短链表
        unsigned int len2=getLen(pHead2);
        ListNode *shortList,*longList;
        if(len1<len2)
        {
            shortList=pHead1;
            longList=pHead2;
        }
        else{
            shortList=pHead2;
            longList=pHead1;
        }
        for(int i=0;i<abs(len1-len2);i++)//截短长链表和短的一样
            longList=longList->next;
        while(longList && shortList && longList!=shortList)//找到第一个公共结点
        {
            longList=longList->next;
            shortList=shortList->next;
        }
        return shortList;
    }
};