//https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
//非回溯的深度优先
class Solution {
public:
    int a[101][101];
    int k;
    int ans = 0;
    int get(int x) {
        int s = 0;
        while(x > 0) {
            s+= x % 10;
            x/=10;
        }
        return s;
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool check(int x, int y) {
        return get(x) + get(y) <= k;    
    }
    int n, m;
    void dfs(int x, int y) {
        if(x < 0 || x >= m || y<0 || y>=n || a[x][y] == 1)  return;
        if(!check(x, y)) return;
        a[x][y] = 1;
        ans++;
        for(int i = 0; i<4; i++) {
            int x1 = dx[i] +x;
            int y1 = dy[i] +y;
            dfs(x1, y1);
        }
    }

    int movingCount(int m1, int n1, int kq) {
        k = kq;
        m = m1;
        n = n1;
        dfs(0, 0);
        return ans;

    }
};
