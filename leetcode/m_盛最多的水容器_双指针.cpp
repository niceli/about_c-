//https://leetcode-cn.com/problems/container-with-most-water/
inline int max(int a, int b) {
    return a > b ? a : b;
}
inline int min(int a, int b) {
    return a > b ? b : a;
}

inline int so(vector<int>& h) {
    int i =0, j = h.size() -1;
    int ans = 0;
    while(i<j) {
        ans = max(ans, (j - i) * min(h[i], h[j]));
        if(h[j] > h[i]) i++; else j--;
    }
    return ans;
}
