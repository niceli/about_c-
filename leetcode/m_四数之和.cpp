//https://leetcode-cn.com/problems/4sum/
//模拟 固定两个值，然后 范围缩小后两个值
//注意重复组合
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int s = nums.size();
        if(s < 4) return  ans;

        sort(nums.begin(), nums.end());

        for( int a = 0; a<= s- 4; a++) {
            if(a > 0 && nums[a -1] == nums[a]) continue;
            if( nums[a] > target && nums[a + 1] >= 0) continue;
            if( nums[a] < target && nums[s-1] <= 0) continue;
            for(int b = a + 1; b <= s-3; b++) {
                if(b > a+1 && nums[b -1] == nums[b]) continue;
                int c = b + 1, d = s - 1;
                int tm = nums[a] + nums[b];
                if( tm > target && nums[c] >= 0) continue;
                if( tm < target && nums[d] <= 0) continue;
                while( c < d) {
                    int t = tm + nums[c] + nums[d];
                    if(t == target) {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        d--;
                        while(c < d && nums[c] == nums[c-1]) c++;
                        while(c < d && nums[d] == nums[d+1]) d--;
                    } else if( t > target) {
                        d--;
                    } else {
                        c++;
                    }
                        
                }
            }
        }
        return ans;
    }
};
