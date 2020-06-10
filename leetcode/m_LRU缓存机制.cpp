//https://leetcode-cn.com/problems/lru-cache/
//增加首位节点，更少判断
class LRUCache {
public:
struct N {
        int i;
        int k;
        N* pre = NULL;
        N* next = NULL;
        N(int ii, int b) {
            i = ii;
            k = b;
        }
    };
 map<int, N*> m;
    int size = 0;
    int ts = 0;
    N* t = NULL;
    N* h = NULL;
    LRUCache(int capacity) {
        size = capacity;
        m.clear();
        t = NULL;
        h = NULL;
        ts = 0;
    }
    
    int get(int key) {
        if( m.count(key) > 0) {
            N* n = m[key];
            if( n == t) {
                return n->i;
            } else if( n == h) {
                h = n->next;
                h->pre = NULL;
                t->next = n;
                n->pre = t;
                t = n;
                n->next = NULL;
                
            } else {
                n->pre->next = n->next;
                n->next->pre = n->pre;
                t->next = n;
                n->pre = t;
                t = n;
                n->next = NULL;
            }
            return n->i;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if( m.count(key) > 0) {
            N* n = m[key];
            n->i = value;
            if( n == t) {
                return;
            } else if( n == h) {
                h = n->next;
                h->pre = NULL;
                t->next = n;
                n->pre = t;
                t = n;
                n->next = NULL;
            } else {
                n->pre->next = n->next;
                n->next->pre = n->pre;
                t->next = n;
                n->pre = t;
                t = n;
                n->next = NULL;
            }
        } else {
            N* nt = new N(value, key);
            m[key] = nt;
            if(t) {
                t->next = nt;
                nt->pre = t;
                t = nt;
            } else {
                h = t = nt;
            }
            ts++;
            if( ts > size) {
                ts = size;
                m.erase(m.find(h->k));
                if(t == h) {
                    t = h->next;
                }
                h = h->next;
                if(h) h->pre = NULL;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
