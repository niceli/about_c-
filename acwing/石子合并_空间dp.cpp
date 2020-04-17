//https://www.acwing.com/problem/content/284/
//先枚举距离
//然后是左右端点

#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n; 
    cin >> n;
    int v[n + 1];
    memset(v, 0, sizeof v);
    for(int i = 1; i<=n; i++) scanf("%d", v+i), v[i]+= v[i-1];
    int dp[n+1][n+1];
    memset(dp, 0, sizeof dp);
    
    
    for(int len = 2;  len <= n; len ++) {
        for(int i = 1; i+len - 1<=n ;i ++) {
            int j = i+len -1;
            dp[i][j] = 1e9;
            for(int k = i; k<j ;k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + v[j] - v[i-1]);
            }
        }
    }

    cout<<dp[1][n]<<endl;
    return 0;
}
