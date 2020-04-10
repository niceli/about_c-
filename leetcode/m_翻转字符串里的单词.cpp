//https://leetcode-cn.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        if(len == 0) return "";
        int i = 0, j = len -1;
        while( i< len && s[i] == ' ') i++;
        while( j >=0 && s[j] == ' ') j--;
        if(i > j) return "";
        char ans [j -i +2];
        int a = 0;
        while( j >= i) {
            int t = j;
            while(t >= i && s[t] != ' ') t--;
            if(a > 0) ans[a++] = ' ';
            for(int b = t + 1; b<=j; b++) ans[a++] = s[b];
            j = t;
            while(j >= i && s[j] == ' ') j--;
        }
        ans[a] = '\0';
        return ans;
    }
};
