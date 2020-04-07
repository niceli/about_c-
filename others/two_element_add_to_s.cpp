/*输入一个递增排序的数组和一个数字S，在数组中查找两个数，
是的他们的和正好是S，如果有多对数字的和等于S，输出两个数
的乘积最小的
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int i=0;
        vector<int> r;
        int size = array.size();
        for(;i<size;i++){
            if(array[i]>=sum) break;
        }
        for(int j = 0;j<i;j++){
            for(int m = i-1;m>j;m--){
                if(array[j]+array[m] == sum){
					r.push_back(array[j]);
                    r.push_back(array[m]);
                    return r;
                }else if(array[j]+array[m]<sum){
                    break;
                }
            }
        }
        return r;
    }

};
//method 2
vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int i=0;
        vector<int> r;
        int size = array.size();
        for(;i<size;i++){
            for(int j= size-1;j>i;j--){
                if(sum == array[i]+array[j]){
                    r.push_back(array[i]);
                    r.push_back(array[j]);
                    return r;
                }else if(sum > array[i]+array[j]){
                    break;
                }
            }
        }
        return r;
    }
