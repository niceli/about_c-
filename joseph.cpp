class Solution {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {	if(n == 0||m == 0) return -1;
        int a=0;
        for(int i=2;i<=n;i++){
            a = (a+m)%i;
        }
        return a;
    }
};
// n:number of people(from 0- n-1)
// m:cycle-length
//f1 = 0
//fn = (f(n-1)+m)%n;
