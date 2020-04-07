/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点
，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 
处理后为 1->2->5

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
       if(pHead == NULL||pHead->next == NULL) return pHead;
       ListNode *h = pHead;
       ListNode *m = NULL;
       ListNode *p = pHead;
       int tmp= pHead->val;
       int c = 1;
       pHead = pHead->next;
       while(pHead){
		if(pHead->val == tmp){
            c++;
        }else{
            if(c == 1){
                if(m == NULL){
                    m = p;
                    h = p;
                }else{
                    h->next = p;
                    h = h->next;
                }
            }
			tmp = pHead->val;
            c =1;

        }
       	p = pHead;
	    pHead = pHead->next;
       }
        if(c == 1&&m == NULL){
            m = p;
            return m;
        }
        if(c==1){
            h->next = p;
            h= h->next;
        }
        h->next = NULL;
        return m;
    }
};
//method 2
ListNode* deleteDuplication(ListNode* pHead)
    {
       ListNode *h = new ListNode(0);
        h->next = NULL;
       ListNode *pre = h;
       while(pHead&&pHead->next){
	   	if(pHead->val == pHead->next->val){
            int tmp = pHead->val;
            while(pHead&&pHead->val==tmp){
                pHead=pHead->next;
            }
        }else{
			pre->next = pHead;
            pre = pre->next;
            pHead = pHead->next;
        }
       }
        if(pHead) pre->next = pHead;
        else pre->next =NULL;
        return h->next;
    }
