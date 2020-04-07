/*输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> r;
        int n = k--;
        if(input.size()<k||input.size() == 0) return r;
        r.push_back(input[0]);
        while(k--){
            
            for(int i=r.size()-1;i>=0;i--){
                if(input[n-k-1]>r[i]){
                    r.insert(r.begin()+i+1,input[n-k-1]);
                    break;
                }
                if(i == 0) r.insert(r.begin(),input[n-k-1]);
            }
           
        }
        for(int i = n;i<input.size();i++){
            for(int j=0;j<n;j++){
                if(input[i]<r[j]){
                    r.erase(r.begin()+n-1);
                    r.insert(r.begin()+j,input[i]);
                    break;
                }
            }
        }
        return r;
    }
   
};
//method 2 bubble sort
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> r;
        int s = input.size();
        if(s<k) return r;
        int tmp;
        for(int i = 0;i<k;i++){
            for(int j=1;j<input.size()-i;j++){
                if(input[j-1]<input[j]){
                    tmp = input[j];
                    input[j] = input[j-1];
                    input[j-1] = tmp;
                }
            }
            r.push_back(input[s-i-1]);
        }
        return r;
    }
};

