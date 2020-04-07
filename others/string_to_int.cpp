/*将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
*/
class Solution {
public:
    int StrToInt(string str) {
        int a=0;
        for(int i=1,j=str.length()-1;j>=0;j--,i*=10){
            if(str[j] == '+')break;
            if(str[j] == '-'){
                a = 0-a;
                break;
            }
            if(str[j]-'0'<0||str[j]-'0'>9) return 0;
			a+=(str[j]-'0')*i;
        }
        return a;
    }
};
