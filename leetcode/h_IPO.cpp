//https://leetcode-cn.com/problems/ipo/submissions/
//贪心

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
    int s = p.size();
	
    priority_queue<int, vector<int>, greater<int> > xq;
    bool sl = false;
    for(int i = 0; i<s; i++) {
        if(c[i] > w) {
            sl = true;
            break;
        }
    }

    if(!sl) {
        for(int i = 0; i< s;i++) {
            xq.push(p[i]);
            if(xq.size() > k) xq.pop();
        }
        while(!xq.empty()) {
            w+= xq.top();
            xq.pop();
        }
        return w;
    }

    priority_queue<int> q;
    vector<int> order(s);
	for(int i =0; i< s; i++) order[i] = i;
	sort(order.begin(), order.end(),[&](const int a, const int b) {
		if(c[a] == c[b]) return p[b] > p[a];
		return c[a] < c[b];
	});

	
	int lastM = -1;
	for(int i = 0;i< s && k > 0;) {
		int pos = order[i];
		//printf("pos %d c %d last %d w %d \n", pos, c[pos], lastM, w);
		if(w >= c[pos]) {
			if(p[pos] > lastM) {
				if(lastM != -1) {
					q.push(lastM);
				}
				lastM = p[pos];	
			}else {
				q.push(p[pos]); 
			}
			i++;
		}else {
			if(lastM == -1) {
				if(!q.empty()) {
					lastM = q.top();
					q.pop();
				} else {
					break;
				}
			} else {
				if(!q.empty()) {
					int r = max(q.top(), lastM);
					w+=r;
					if(r == lastM) {
						lastM = -1;
					} else {
						q.pop();
					}
				} else {
					w+= lastM;
					lastM = -1;
				}
				k--;
			}
		}		
	}	

	if(lastM > 0) q.push(lastM);
	while(!q.empty() && k) {
		w+= q.top();
		q.pop();
		k--;
	}	
	
	return w;
    }
};
