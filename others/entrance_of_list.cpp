/*一个链表中包含环，请找出该链表的环的入口结点。
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		map<int,int> m;
        while(pHead!=NULL){
            if(m[pHead->val] == 1){
                return pHead;
            }else{
				m[pHead->val]++;
            }
            pHead = pHead->next;
        }
        return NULL;
    }
};
//method 2:先通过差速，找到环中的相遇点，移动其中一个，记录步数得到环大小c，然后从起始点，先行c另一点在开始，逐一向前，相同点即为入口。
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
		if(pHead == NULL||pHead->next == NULL){
            return NULL;
        }
        ListNode* s = pHead;
        ListNode* f = pHead->next;
        while(f&&s){
            if(s->val == f->val) break;
            s = s->next;
            f = f->next->next;
        }
        if(f==NULL||s == NULL) return NULL;
        int count = 0;
        while(true){
            s = s->next;
            count++;
            if(s->val == f->val) break;
        }
        s  = pHead;
        while(count--){
			s = s->next;
        }
        while(true){
			
            if(s->val == pHead->val){
				return pHead;
            }
            s = s->next;
            pHead = pHead->next;
        }
        return NULL;
    }
};
