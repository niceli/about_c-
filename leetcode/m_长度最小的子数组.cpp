//https://leetcode-cn.com/problems/minimum-size-subarray-sum/solution/
//维护满足和的区间，然后每次当和大于s时候，尝试踢出靠近维护区间起始点的数值
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int f = 0, ts = 0;
        int ans = nums.size() + 1;
        for(int i = 0; i< nums.size(); i++) {
            int t = nums[i];
            ts += t;
            while(ts > s && f < i) {
                if(ts - nums[f] >= s) {
                    ts-=nums[f];
                    f++;
                }else {
                    break;
                }
            }
            if(ts >= s) ans = min(ans, i -f + 1);
        }
        return ans == nums.size() + 1? 0 : ans;
    }
};
