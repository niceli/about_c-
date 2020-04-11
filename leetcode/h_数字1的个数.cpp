//https://leetcode-cn.com/problems/number-of-digit-one/
//100, 101, 1, 0
// 123 ->  0 ~ 23, 24 ~ 123
// 223 -> 0 ~ 23, 24 ~ 223
class Solution {
public:
    int get(int a, int n) {
        if(n == 0) return a >=1 ? 1: 0;
        int p = pow(10, n);
        if(p > a) return get(a, n-1); // 10001空位的情况
        int l = get(a % p, n-1);
        int c = 0;
        int f = a /p;
        if(f == 1) {  //首项为1时
            c+= a % p +1;
        } else {
            c+= p;
        }
        c += f * n * pow(10, n-1); //其他项， *p/10 存在越界
        return l + c; //首项（是否是1 ？ 后面的数字+1 ：p个） + 首项 * 后项个数 * p/10
    }

    int getN(int a) {//算位数
        int c = 0;
        while(a) {
            c++;
            a/=10;
        }
        return c;
    }

    int countDigitOne(int n) {
        if(n == 0) return 0;
        int c = getN(n);
        return get(n, c-1);
    }
};
