//https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/
//1 差速法（k<=size）
//2 求长 递归法 (k不限制)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//差速
int kthToLast(ListNode* head, int k) {
        ListNode* t = head, *m = head;
        while(k--) {
            t = t->next;
        }

        while(t) {
            t = t->next;
            m = m->next;
        }
        return m->val;
    }


class Solution {
public:
    ListNode* ans;
    void v(ListNode* n, int c, int& k) {
        if(n) {
            c++;
            v(n->next, c, k);
            k--;
            if(k == 0) {
                ans = n;
            }
        } else {
           if(k > c) k%=c;
        }
    }

    int kthToLast(ListNode* head, int k) {
        if(!head) return -1;
        v(head, 0, k);
        return ans->val;
    }
};
