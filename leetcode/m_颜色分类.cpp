//https://leetcode-cn.com/problems/sort-colors/
//荷兰国旗
void sortColors(vector<int>& nums) {
        int a = 0, b = nums.size() -1, c = 0;
        while( c <= b) {
            if(nums[c] == 0) {
                swap(nums[a], nums[c]);
                a++;
                c++;
            } else if( nums[c] == 2) {
                swap(nums[c], nums[b]);
                b--;
            } else {
                c++;
            }
        }  
    }
