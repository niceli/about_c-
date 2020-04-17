//https://leetcode-cn.com/problems/number-of-ways-to-paint-n-x-3-grid/submissions/
const int M = 1e9 + 7;
class Solution {
public:
    int numOfWays(int n) {
        long long  aba = 6, abc = 6;
        if(n == 1) return aba + abc;
        long long  l, r;
        while(--n) {
            l = (aba * 3 + abc * 2) % M;
            r = (aba * 2 + abc * 2) % M;
            aba = l;
            abc = r;
        }
        return (abc + aba) % M;
    }
};


//dp每次根据上下，左右是否重复判断能否加入答案
const int M=1e9+7;
class Solution {
    public:
    int dp[5001][3][3][3];

    int numOfWays(int n) {
        for (int i = 0; i < n; i++) {
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    for (int c = 0; c < 3; c++) {
                        if (a != b && b != c) {

                            if (i > 0) {
                                for (int a1 = 0; a1 < 3; a1++) {
                                    for (int b1 = 0; b1 < 3; b1++) {
                                        for (int c1 = 0; c1 < 3; c1++) {
                                            if (a1 != a && b1 != b && c1 != c) {
                                                dp[i][a][b][c] = (dp[i][a][b][c] + dp[i - 1][a1][b1][c1]) % M;
                                            }
                                        }
                                    }
                                }
                            } else {
                                dp[i][a][b][c] = 1;
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int a1 = 0; a1 < 3; a1++) {
            for (int b1 = 0; b1 < 3; b1++) {
                for (int c1 = 0; c1 < 3; c1++) {
                    ans = (ans + dp[n - 1][a1][b1][c1]) % M;

                }
            }
        }
        return ans;
    }
};
