//https://leetcode-cn.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/
//通过set有序，每次取出最小的，尝试每一行向后移动位置（默认每行非减)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> sv;
        set<pair<int, vector<int>>> s;
        int n = mat.size(), m = mat[0].size();
        int sum = 0;
        for(int i = 0; i< n; i++) sum += mat[i][0];
        s.insert({sum, vector<int>(n,0)});
        while(sv.size() != k) {
            auto t = s.begin();
            int tsum = t->first;
            auto vc = t->second;
            s.erase(t);
            sv.push_back(tsum);
            for(int i = 0; i<n; i++) {
                if( vc[i] +1 < m) {
                    vector<int> tv = vc;
                    tv[i]++;
                    s.insert({tsum - mat[i][vc[i]] + mat[i][vc[i]  + 1], tv});
                }
            }
        }
        return sv.back();
    }
};
