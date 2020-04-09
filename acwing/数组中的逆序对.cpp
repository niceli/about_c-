//https://www.acwing.com/problem/content/61/
//归并然后根据前边部分插入位置，判断在其之前有多少后面部分的元素
class Solution {
public:
    int ans = 0;
    void mr(vector<int>& v, vector<int>& tm, int f, int t) 
    {
        if(f >= t) return;
        int m = (f + t) >>1;
        mr(v, tm, f, m);
        mr(v, tm, m+1, t);
        int k = f, a = f, b = m+1;
        while( a<=m && b<=t) {
            if(v[a] < v[b]) {
                ans += (b - m -1);
                tm[k++] = v[a++];
            } else {
                tm[k++] = v[b++];
            }
        }
        
        while(a <= m) {
            ans += t - m;
            tm[k++] = v[a++];
        }
        
        while( b<=t) tm[k++] = v[b++];
        for(int i = f; i<=t; i++) v[i] = tm[i];
    }
    
    int inversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tm(n);
        mr(nums, tm, 0, n-1);
        return ans;
    }
};
