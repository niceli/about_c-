//https://leetcode-cn.com/problems/jump-game-ii/

int jump(vector<int>& nums) {
	int size = nums.size();
	if(size <=1 ) return 0;
    	if(nums[0] >= size -1) return 1;
	vector<int> v (size, INT_MAX);
	v[0] = 0;
    	int lm = -1; //记录上次跳到的最大位置
	for(int i = 0; i< size; i++) {
		int t = nums[i];
        	int j = max(lm + 1, i+1); //计算应该起始位置 上次最大位置加1 还是后一位置
		for(; j<=i+t && j < size; j++) {
			v[j] = min(v[j], v[i] + 1);
            		if(j== size -1) return v[j]; //遇到最后一个点 就完成
		}
        	lm = max(lm, j-1); //更新本次到达最大位置
	}
	return v[size -1];
}
//每次记录一次跳跃最大位置，然后更新step
int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }


