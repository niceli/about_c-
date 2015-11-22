/*给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。
http://www.nowcoder.com/practice/94a4d381a68b47b7a8bed
86f2975db46?rp=3&ru=/ta/coding-interviews&qru=/ta/codin
g-interviews/question-ranking
*/
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	vector<int>v;
        v.push_back(1);
        int r = 1;
        for(int i=0;i<A.size()-1;i++){
            r*=A[i];
            v.push_back(r);
        }
        r = 1;
        for(int i=A.size()-1,j=v.size()-2;i>=1;i--,j--){
            r*=A[i];
            v[j]*=r;
        }
        return v;
    }
};
