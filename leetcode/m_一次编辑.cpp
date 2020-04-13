//https://leetcode-cn.com/problems/one-away-lcci/
//分情况讨论 长度差，不同的位置
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int fl = first.length(), sl = second.length();
        if(sl < fl) return oneEditAway(second, first);

        if(sl - fl > 1) return false;
        if(fl == 0) return true; //**
        int c = 0;
        if(sl == fl) {
            for(int i = 0; i< sl && c <2; i++) {
                if(first[i] != second[i]) c++;
            }
        } else {
            if(first[0] == second[0]) {
                for(int i = 0, j = 0; i< fl && j<sl && c <2;j++) {
                    if(first[i] != second[j]) {
                        c++;
                    } else {
                        i++;
                    }
                }   
            } else if(first[fl -1] == second[sl-1]) {
                for(int i = fl-1, j = sl-1; i>=0 && j>=0 && c <2;j--) {
                    if(first[i] != second[j]) {
                        c++;
                    } else {
                        i--;
                    }
                }  
            } else {
                return false;
            }
        }
        return c<2;
    }
};
