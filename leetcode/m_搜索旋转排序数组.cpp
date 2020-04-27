//https://leetcode-cn.com/problems/search-in-rotated-sorted-array

#include <bits/stdc++.h>
using namespace std;

int rt;
int fi(vector<int>& v, int f, int t, int& ta) {
	if( f > t) return -1;
	int m = (f+ t) >> 1;
	if(v[m] == ta) {
		return m;
	}
	if(v[m] >= v[f]) {
		if(v[f] <= ta && ta < v[m]) {
			return fi(v, f, m-1, ta);
		} else {
			return fi(v, m+1, t, ta);
		}
	} else {
		if( v[m] < ta && ta <= v[t]) {
			return fi(v, m+1, t, ta);
		} else {
			return fi(v, f, m-1, ta);
		}
	}
}

int search(vector<int>& nums, int target) {
	int size = nums.size();
	if(size == 0) return -1;
	rt = nums[0];
	return fi(nums, 0, nums.size() -1, target);
}
