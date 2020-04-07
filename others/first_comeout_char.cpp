/*在一个字符串(1<=字符串长度<=10000，全部由字母组成)中
找到第一个只出现一次的字符的位置。若为空串，返回-1。位置
索引从0开始
*/
//method 1 穷举
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
      
        for(int i=0;i<str.length();i++){
            for(int j=0;j<str.length();j++){
                if(i == j) continue;
                if(str[i] == str[j]) break;
                if(j == str.length()-1) return i;
            }
            
            
        }
        return -1;
    }
};
//method 2 填字母
class Solution {
public:
    int c[52];
    int FirstNotRepeatingChar(string str) {
      	for(int i=0;i<str.length();i++){
            int index;
            if(str[i]-'a'>=0) index =str[i] - 'a';
            else index = 26+str[i]-'A';
            if(c[index] == 0){
                c[index] = i+1;
            }else{
                c[index] = -2;
            }
        }
        int tmp = -1;
        for(int i=0;i<52;i++){
            if(c[i] >0&&tmp == -1){
            	tmp = c[i]-1;
            }else if(c[i]>0&&(c[i]-1<tmp)){
                tmp = c[i] -1;
            }
        }
        return tmp;
    }
};
