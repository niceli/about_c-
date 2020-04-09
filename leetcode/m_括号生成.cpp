//https://leetcode-cn.com/problems/generate-parentheses/
//生成过程中 ).remain >= (.remain
//动态规划 dp[i] = "(" + dp[j] + ")" + dp[i -j -1];  dp[i] 表示i对括号时能生成的不同字符串
class Solution {
public:
    vector<string> ans;
    int n;
    void gen(int a, int b, char* c) {
        if(a == 0 && b == 1) {
            c[2 * n -1] = ')';
            c[2 * n] = '\0';
            ans.push_back(c);
        } else if(a <= b)  {
            if(a >=1) {
                c[2 * n -a - b] = '(';
                gen(a-1, b, c);
            }
            if(b >=1) {
                c[2 * n -a - b] = ')';
                gen(a, b-1, c);
            }
        }
    }

    vector<string> generateParenthesis(int n1) {
        n = n1;
        char c[2 * n + 1];
        c[0] = '(';
        gen(n-1, n, c);
        return ans;
    }
};
