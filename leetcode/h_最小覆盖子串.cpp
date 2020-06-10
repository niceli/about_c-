//https://leetcode-cn.com/problems/minimum-window-substring/
class Solution {
public:
    int f[257];
    int ff[257];
    bool check() {
        for(int i = 0; i<=256; i++) {
            if(f[i] < ff[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) { //构造窗口，维护当前窗口内的 出现在t中的字母， 当满足时候，检查是否能从头踢出，维护最小长度
        int sl = s.length(), tl = t.length();
        if(sl < tl) return "";
        for(auto x: t) ff[x]++;
        queue<int> q;
        int ans = sl +1;
        int idx = -1;
        bool isCheck = false;
        for(int i = 0; i< sl; i++) {
            char c = s[i];
            if(ff[c] >  0) {
                q.push(i);
                f[c]++;
                if(!isCheck && check()) {
                    isCheck = true;
                }
                while(!q.empty() && isCheck) {
                    int ft = q.front();
                    if(f[s[ft]] > ff[s[ft]]) {
                        q.pop();
                        f[s[ft]]--;
                    } else {
                        break;
                    }
                }
                if(isCheck) {
                    int nl = i - q.front() + 1;
                    if( nl < ans) {
                        ans = nl;
                        idx = q.front();
                    }
                }
            }
          //printf("%c %d %d \n", c, ans, idx);
        }
        return isCheck ? s.substr(idx, ans) : "";
    }
};
