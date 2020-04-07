/*统计一个数字在排序数组中出现的次数。*/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int count = 0;
        int s = get(0,data.size()-1,data,k);
        int t =s;
        if(s<0) return 0;
        while(s>=0&&data[s--] == k){
            count++;
        }
        while(data[++t] == k&&t<data.size()){
			count++;
        }
        return count;
        
    }
    int get(int b,int e,vector<int> d,int k){
		if(b>e) return -1;
        int mid = (b+e)/2;
        if(d[mid]>k){
			return get(b,mid-1,d,k);
        }else if(d[mid]<k){
			return get(mid+1,e,d,k);
        }else{
            return mid;
        }
    }
};
