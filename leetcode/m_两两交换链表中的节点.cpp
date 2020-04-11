//https://leetcode-cn.com/problems/swap-nodes-in-pairs/
//增加前置节点，每次判断两个，注意最后尾设为null
ListNode* swapPairs(ListNode* head) {
 	ListNode* h = new ListNode(-1);
 	h->next = head;
 	ListNode* l = h;
 	ListNode* t = head;
 	ListNode* a;
 	ListNode* b = NULL;
 	while(t) {
 		a = t;
 		t = t->next;
 		if(t) {
 			b = t;
 			t = t->next;
 		}

 		if(b) {
 			b->next = a;
 			h->next = b;
 		} else {
 			h->next = a;
 		}
 		h = a;

 		b = NULL;
 	}

 	h->next = NULL;
 	return l->next;       
 }
