/*输出所有和为S的连续正数序列。序列内按照从小至大的顺序，
序列间按照开始数字从小到大的顺序
:对于sum-1~2分别求其商，然后对商附近的值进行尝试求和。
*/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> v;
        for(int i = sum-1;i>=2;i--){
            vector<int> t;
            int m = sum/i;
            for(int j=m-i+2;j<=m;j++){
                if(j<=0) continue;
                if((2*j+i-1)*i/2 == sum){
                    for(int m = j;m<j+i;m++){
                        t.push_back(m);
                    }
                    v.push_back(t);
                    break;
                }
            }
        }
        return v;
    }
};
//method 2 穷举
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> v;
        for(int i = 1;i<=sum/2;i++){
            vector<int> r;
           int tmp = i;
           int t = i;
            r.push_back(i);
            while(tmp<sum){
                tmp+=(++t);
                r.push_back(t);
                if(tmp == sum) v.push_back(r); 
            }
        }
        return v;
    }
};
//method 3. 等差公式
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> r;
        double a = 0;
        for(int i=sum-1;i>=2;i--){
        	a =(2*sum+i-i*i)/(2*i*1.0);
            if(a - (int)a==0&&a>0){
                vector<int> v;
                for(int j=a;j<a+i;j++){
                    v.push_back(j);
                }
                r.push_back(v);
            }
        }
        return r;
    }
};
