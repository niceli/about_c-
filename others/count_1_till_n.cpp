/*求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6
次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍
化,可以很快的求出任意非负整数区间中1出现的次数。
:对于没一位进行计算，当其为1，0，>=2时，出现1的个数。
*/
class Solution {
public:

    int NumberOf1Between1AndN_Solution(int n)
    {
        int t = 0;
        for(int i=1;i<=n;i*=10){
            int a = n/i,b=n%i,c=a%10,e=a/10;
            if(c == 0) t+=e*i;
            if(c == 1) t+=e*i+b+1;
            if(c >= 2) t+=(e+1)*i;
        }
        return t;
    
    }
    
};
