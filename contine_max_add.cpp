/*{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	vector<int> v;
        if(array.size()== 0) return 0;
        int tmp=0;
        int max = array[0];
        for(int i=0;i<array.size();i++){
            max=array[i]>max?array[i]:max;//防止全负；
            if(array[i] == 0) continue;
            if(tmp == 0){
                tmp = array[i];
                continue;
            }
            if(array[i]*tmp<0){
				v.push_back(tmp);
                tmp = array[i];
            }else{
				tmp+=array[i];
            }
        }
        v.push_back(tmp);
        int i = 0;
        tmp = 0;
        if(v[0]<0) i=1;
        for(;i<v.size();i=i+2){
            tmp = v[i];
            for(int j=i+1;j<v.size();j=j+2){
                int l = v[j];
                if(j<v.size()-1) l+=v[j+1];
                if(l>=0){
                    tmp+=l;
                }else{
					break;
                }
            }
            max = max>tmp?max:tmp;
        }
        
        return max;
    }
};
