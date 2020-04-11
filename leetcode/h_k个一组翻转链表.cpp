//https://leetcode-cn.com/problems/reverse-nodes-in-k-group/submissions/
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
   ListNode* flat(ListNode* h, ListNode* t) { //t之前的反转
 	ListNode* a = NULL;
 	while(h!= t) {
 		ListNode* tt = h->next;
 		h->next = a;
 		a = h;
 		h = tt;
 	}
 	return a;
 }

 ListNode* reverseKGroup(ListNode* head, int k) {
 	 ListNode* h = new ListNode(-1);
 	 ListNode* l = h;
	 ListNode* t = head;
	 while(t) {
	 	int i = 0;
	 	ListNode* tt = t;
	 	while(i<k && t) {//判断长度是否符合并移动
	 		t = t->next;
	 		i++;
	 	}
	 	if(i == k) { //长度满足
	 		l->next = flat(tt, t);
	 		l = tt;
	 	} else {
	 		l->next = tt;
	 		break;
	 	}
	 }
	 return h->next;     
 }
};



//optimised

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
  ListNode* flatK(ListNode* h, int k, ListNode** n) {
 	int tk = k;
 	ListNode* a = NULL;
 	while(k-- > 0 && h) { 
 		ListNode* l = h->next;
 		h->next = a;
 		a = h;
 		h = l;
 	}
    k = k+1; //因为先--
 	if(k == 0) *n = h;
 	if(k != 0) {
 	    return flatK(a, tk - k, n); //不足时恢复
 	}

 	return a;
 }

 ListNode* reverseKGroup(ListNode* head, int k) {
 	 ListNode* h = new ListNode(-1);
 	 ListNode* l = h;
	 ListNode* t = head;
	 ListNode* n = NULL;
	 while(t) {
	 	l->next = flatK(t, k, &n); //n代表 t应该的下个位置
	 	l = t;
	 	t = n;
	 }
	 return h->next;     
 }
};
