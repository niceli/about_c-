//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
//如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

class Solution {
public:
    int i=0;
    bool VerifySquenceOfBST(vector<int> sequence) {
        int size = sequence.size();
		if(!(i+size)) return false;
        if(!size) return true;
        i++;
        vector<int> l;
        vector<int> r;
        
        int tmp = sequence[size-1];
        int i;
        for(i=0;i<size-1&&sequence[i]<tmp;i++){
                l.push_back(sequence[i]);
        }
        for(;i<size-1;i++){
            if(sequence[i] == tmp||sequence[i]<tmp) return false;
            r.push_back(sequence[i]);
        }
        return true&&VerifySquenceOfBST(l)&&VerifySquenceOfBST(r);
    }
};
//method 2
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0) return false;
        return check(sequence,0,sequence.size()-1);
    }
    bool check(vector<int> v,int b,int e){
        if(b >= e) return true;
        int tmp = v[e];
        int i=b;
        for(;i<e&&v[i]<tmp;i++){};
        int m = i-1;
        for(;i<e;i++){
            if(v[i]<=tmp) return false;
        }
        return check(v,b,m)&&check(v,m+1,e-1);
    }
};
