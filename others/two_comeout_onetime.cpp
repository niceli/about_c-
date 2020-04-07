/*一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
:先对每个元素异或操作，对于结果查找1的位置，也就是出现一次的两个元素不同的位，
然后将所有元素根据这个位的不同，分堆，再进行异或，结果即为所求。
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    	if(data.size()<2) return;
        int r = data[0];
        for(int i=1;i<data.size();i++){
            r^=data[i];
        }
        if(r == 0) return;
        int c=1;
        while(true){
            if(r&c)break;
            else c=c<<1;
        }
        *num1 = 0;
        *num2 = 0;
        for(int i=0;i<data.size();i++ ){
            if(data[i]&c) *num1^=data[i];
            else *num2^=data[i];
        }
    
    }
    
};
