/*在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个
数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
*/
class Solution {
public:
    int InversePairs(vector<int> data) {
        int c =0;
        for(int i=0;i<data.size();i++){
            for(int j=i+1;j<data.size();j++){
                if(data[i]>data[j]) c++;
            }
        }
        return c;
    } 
};
