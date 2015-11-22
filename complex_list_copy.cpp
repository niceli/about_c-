/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，
一个指向下一个节点，另一个特殊指针指向任意一个节点）。
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
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;
        map<RandomListNode*,RandomListNode*> m;
        RandomListNode* tmp = new RandomListNode(pHead->label);
        RandomListNode* h = tmp;
        RandomListNode* n = pHead;
        m[pHead] = pHead->random;
        while(pHead->next){
            pHead = pHead->next;
            tmp->next = new RandomListNode(pHead->label);
            tmp = tmp->next;
            m[pHead] = tmp;
        }
        tmp = h;
        while(n){
            tmp->random = m[n->random];
            n = n->next;
            tmp = tmp->next;
        }
        return h;
    }
};
//method 2
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return NULL;  
        RandomListNode* h = pHead;
        RandomListNode* n = pHead;
        while(pHead){//add copy one after each node
            RandomListNode* tmp = new RandomListNode(pHead->label);
            tmp->next = pHead->next;
            pHead->next = tmp;
            pHead = tmp->next;
        }
        pHead = n;
        h = pHead->next;
       while(pHead){//copy the random node
           if(pHead->random!=NULL){
               pHead->next->random = pHead->random->next;
           }
            pHead = pHead->next->next;
        }
        pHead = n->next;
        while(pHead){//construct the result and recover the origin one
            n->next = n->next->next;
            n = n->next;
            if(!pHead->next) break;
            pHead->next = pHead->next->next;
            pHead = pHead->next;
        }
        
        return h;
    }
};
