/*，“student. a am I”。后来才意识到，这家伙原来把
句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
*/
class Solution {
public:
    string ReverseSentence(string str) {
        string s="";
        int c = 0;
        for(int i=str.length();i>=0;i--){
            if(str[i]!=' ') c++;
            else{
                s+=str.substr(i+1,c)+" ";
                c = 0;
            }
        }
        s+=str.substr(0,c);
        return s;
    }
};
