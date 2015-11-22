/*对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，
即“XYZdefabc”
*/
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.length()<n) return "";
        string a = str.substr(0,n);
        a = str.substr(n,str.length()-n)+a;
        return a;
    }
};
//method 2;
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.length()<n) return "";
        int l = str.length();
        str+=str;
        return str.substr(n,l);
        
    }
};
