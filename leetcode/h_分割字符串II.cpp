//https://leetcode-cn.com/problems/palindrome-partitioning-ii/
//中心扩展 + 动态规划

class Solution {
public:
    int minCut(string s) {
         int len = s.length();
       	vector<vector<int>> v(len, vector<int>());
        for(int i = 0; i<len; i++) {
            int a = i-1, b = i+1;
                while(a >= 0 && b < len) {
                    if(s[a] == s[b]) {
                        v[b].push_back(a);
                        a--;
                        b++;
                    }else {
                        break;
                    }
                }
            a = i, b = i+1;
            while(a >= 0 && b < len) {
                    if(s[a] == s[b]) {
                        v[b].push_back(a);
                        a--;
                        b++;
                    }else {
                        break;
                    }
                }
        }

        if(find(v[len-1].begin(), v[len-1].end(), 0) != v[len-1].end()) return 0;

        int f[len];
        memset(f, INT_MAX, sizeof f);
       	f[0] = 1;
        for(int i = 1; i<len; i++) {
            f[i] = f[i-1] + 1;
            for(int x: v[i]) {
                f[i] = min(f[i], x - 1 < 0 ? 1 : f[x-1] + 1);
            }
        }
        return f[len-1] -1;
    }
};
