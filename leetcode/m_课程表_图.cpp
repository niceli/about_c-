//https://leetcode-cn.com/problems/course-schedule

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
	unordered_map<int, vector<int>> m;
	vector<int> v (n, 0);
	for(auto &x: p) {
		m[x[1]].push_back(x[0]);
		v[x[0]]++;
	}
	queue<int> q;
	for(int i = 0; i< n; i++) {
		if(v[i] == 0) q.push(i);
	}
    bool t = false;
	while(!q.empty()) {
		auto z = q.front();
		q.pop();
		if(m.count(z) != 0) {
			for(auto &l : m[z]) {
				v[l]--;
				if(v[l] == 0) {
					q.push(l);
				}
			}
		}
	}
	for(auto &xx: v) {
		if(xx != 0) return false;
	}
	return true;
}
};
