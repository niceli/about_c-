//https://www.acwing.com/problem/content/899/
//两个子序列中的下标，最大长度。最值问题，可以存在重复  划分时，其实考虑的是 ij都不存在；i存在，j不存在；i不存在，j存在；i，j都存在。
//f[i-1][j]代表的是 i-1，j的最大值，包含了 i不存在，j存在的情况。也就是 对于上述状态中重复的部分

#include<iostream>
using namespace std;
const int N = 1010;
int n,m;
char a[N],b[N];
int f[N][N];
int main() {
    cin >> n >> m >> a+1 >> b+1;
    for(int i = 1;i<=n; i++) {
        for(int j= 1; j<=m; j++) {
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if(a[i] == b[j]) f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
        }
    }
    cout << f[n][m] <<endl;
    return 0;
}
