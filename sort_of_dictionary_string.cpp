/*输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有
字符串abc,acb,bac,bca,cab和cba。 结果请按字母顺序输出。
*/
class Solution {
public:
    int size;
    vector<string> Permutation(string str) {
        vector<string> v;
        size = str.size();
        if(size == 0) return v;
        for(int i=1;i<size;i++){
			for(int j=0;j<size-i;j++){
                if(str[j]>str[j+1]){
					swap(str[j],str[j+1]);
                }
            }
        }
        v.push_back(str);
        if(size<2) return v;
        while(getnext(str)){
			v.push_back(str);
        }
        return v;
    }
    bool getnext(string &str){
        int j = size-2;
        for(;j>=0&&str[j]>=str[j+1];j--){}
        if(j<0) return false;
       	int i = size-1;
        for(;i>j&&str[i]<=str[j];i--){}
        if(i == j) return false;
        swap(str[i],str[j]);
        for(int l = j+1,m = size-1;l<m;l++,m--){
            swap(str[l],str[m]);
        }
        return true;
    }
};	
