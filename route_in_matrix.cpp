/*请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移
动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵
中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后
，路径不能再次进入该格子。
*/
class Solution {
public:
    int h,z;
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {	h = cols;
     	z = rows;
		if(str[0] == '\0'||rows == 0|| cols == 0) return false;
        bool *b = new bool[rows*cols]();
    	for(int x = 0;x<rows;x++){
            for(int y=0;y<cols;y++){
               if(check(matrix,x,y,b,0,str)) return true;
            }
        }
        return false;
    }
    bool check(char*m,int x,int y,bool *b,int i,char * str){
       if(str[i] == '\0') return true;
       if(x<0||x>=z||y<0||y>=h||b[x*h+y]||m[x*h+y]!=str[i]) return false;
       b[x*h+y] = true;
       i++;
       if(check(m,x+1,y,b,i,str)||check(m,x-1,y,b,i,str)||check(m,x,y+1,b,i,str)||check(m,x,y-1,b,i,str)){
           return true;
       }
       b[x*h+y] = false;
        return false;
    }


};
