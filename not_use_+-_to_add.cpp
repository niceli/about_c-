class Solution {
public:
    int Add(int num1, int num2){
        int tmp;
		while(num1){
			tmp = num1^num2;//不进位的
            num1 = num1&num2;//进位
            num1 =num1<<1;
            num2 = tmp;
        }
     return num2;
    }
};
