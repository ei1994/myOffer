/*
*
* 面试题26：复杂链表的复制
* 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
* 另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
* （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    void cloneNode(RandomListNode* pHead)
    {
        while(pHead != nullptr)
        {
            RandomListNode* node = new RandomListNode(0);
            node->label = pHead->label;
            node->next = pHead->next;
            pHead->next = node;
            pHead = node->next;
        }
    }
    void random(RandomListNode* pHead)
    {
        while(pHead != nullptr)
        {
            if(pHead->random != nullptr)
                pHead->next->random = pHead->random->next;
            pHead = pHead->next->next;
        }
    }
    RandomListNode* reList(RandomListNode* pHead)
    {
        RandomListNode *root = pHead->next;
        while(pHead->next != nullptr)
        {
            RandomListNode *temp = pHead->next;
            pHead->next = temp->next;
            pHead = temp;
        }
        return root;
    }
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr)
            return nullptr;
        cloneNode(pHead);
        random(pHead);
        return reList(pHead);
    }
};