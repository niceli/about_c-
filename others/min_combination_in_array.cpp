/*输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
则打印出这三个数字能排成的最小数字为321323。
:每两个之间通过组合顺序进行比较，按组成结果较小的顺序，进行元素排序
*/

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        
        string str="";
        sort(numbers.begin(),numbers.end(),cmp);
        for(int i=0;i<numbers.size();i++){
            str+=to_string(numbers[i]);
        }
        return str;
    }
   static bool cmp(int a,int b){
        string c = to_string(a)+to_string(b);
        string d = to_string(b)+to_string(a);
        return c<d;
    }
};
