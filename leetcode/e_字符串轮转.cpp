//https://leetcode-cn.com/problems/string-rotation-lcci/
//kmp求next数组  顺序比较 直到 2l次内 存在完全匹配的，下标 % l
//******  2 * s1 找子串 s2
class Solution {
public:
    int n[100001];
    void build(string s) {
        int i = 0, j = -1;
        n[0] = j;
        while(i< s.length()) {
            if( j == -1 || s[j] == s[i]) {
                n[++i] = ++j;
            } else {
                j = n[j];
            }
        }
    }

    bool isFlipedString(string s1, string s2) {
        int l = s1.length(), r = s2.length();
        if(l != r) return false;
        if(l == 0) return true;
        build(s2);

        int c = 0;
        for(int i = 0,j= 0; i<2 * l;) {
            if(j == -1 || s1[i % l] == s2[j]) {
                i++;
                j++;
                if(j == l) return true;
            } else {
                j = n[j];
            }
        }
        return false;
        
    }
};
