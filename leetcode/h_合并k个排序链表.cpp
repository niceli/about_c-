//https://leetcode-cn.com/problems/merge-k-sorted-lists/
//借助小顶堆 实现每次取最小
 struct cmp
{
	bool operator() (const ListNode* a, const ListNode* b) {
		return a->val > b->val;
	}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
	ListNode* h = new  ListNode(-1);
	ListNode* t = h;
	priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

	for(int i = 0; i<lists.size(); i++) {
		if(lists[i]) pq.push(lists[i]);
	}

	while(!pq.empty()) {
		ListNode* tmp = pq.top(); pq.pop();
		if(tmp->next) {
			pq.push(tmp->next);
		}
		t->next = tmp;
		t = tmp;
	}
	t->next = NULL;
	return h->next;
}
