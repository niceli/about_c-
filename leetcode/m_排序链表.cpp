//https://leetcode-cn.com/problems/sort-list/
//差速指针，归并排序
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || head->next == NULL) return head;
        ListNode* lm;
        ListNode* m = head;
        ListNode* t = head;
        while(t && t->next) {
            lm = m;
            m = m->next;
            t = t->next->next;
        }
        if(lm) lm->next = NULL;
        return sort1(sortList(head), sortList(m));
    }

    ListNode* sort1(ListNode* a, ListNode* b) {
        ListNode* h = new ListNode(-1);
        ListNode* t = h;
        while(a && b) {
            if( a->val < b->val) {
                t->next = a;
                a = a->next;
            } else {
                t->next = b;
                b = b->next;
            }
            t = t->next;
        }
        t->next = a ? a : b;
        return h->next;
    }
};
