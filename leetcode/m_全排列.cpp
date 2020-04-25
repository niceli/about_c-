//https://leetcode-cn.com/problems/permutations/
//回溯
class Solution {
public:
    vector<vector<int>> v;
    int s;
    vector<int> vi;
    vector<int> t;
    void dfs(vector<int>& n, int p) {
        if(p == s) {
            v.push_back(t);
            return;
        }
        for(int i =0 ;i< s;i ++) {
            if(vi[i] == 0) {
                vi[i] = 1;
                t[p] = n[i];
                dfs(n, p+1);
                vi[i] = 0;
            }
        }
        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        s = nums.size();
        t.resize(s);    
        vi.resize(s, 0);
        dfs(nums, 0);

        return v;
    }
};
