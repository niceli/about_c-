/*数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组
{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
如果不存在则输出0。
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    /*	method 1:
    	map<int,int> m;
        for(int i=0;i<numbers.size();i++){
            if(++m[numbers[i]]>numbers.size()/2)
                return numbers[i];
        }
        return 0;*/
        int c =0;
        int t =0;
        for(int i=0;i<numbers.size();i++){
            if(c==0||t==numbers[i]){
                t = numbers[i];
                c++;
            }else{
                c--;
            }    
        }
        c = 0;
        for(int i=0;i<numbers.size();i++){
            if(t == numbers[i]) c++;
            if(c>numbers.size()/2) return t;
        }
        return 0;
    }
};
