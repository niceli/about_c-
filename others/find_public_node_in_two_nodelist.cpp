/*
输入两个链表，找出它们的第一个公共结点。
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        ListNode* t = pHead2;
        while(pHead1!=NULL){
            while(pHead2!=NULL){
                if(pHead1->val == pHead2->val)
                    return pHead1;
                pHead2 = pHead2->next;
            }
            pHead1=pHead1->next;
            pHead2 = t;
        }
        return NULL;
    }
};
