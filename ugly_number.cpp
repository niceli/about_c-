/*把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。*/
class Solution {
public:
   
    int GetUglyNumber_Solution(int index) {
      vector<int> r;
       r.push_back(1);
        int a=0,b=0,c=0;
    	for(int i=2;i<=index;i++){
            int e = r[a]*2;
            int f = r[b]*3;
            int g = r[c]*5;
            int t = min(e,min(f,g));
             r.push_back(t);
            if(t == e){
               a++;
            }
            if(t == f){
                b++;
            }
            if(t == g){
               c++;
            }
            
        }
        return r[index-1];
    }
   
};



    	     
    	      
