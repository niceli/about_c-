//https://leetcode-cn.com/problems/zero-matrix-lcci/
//不使用额外空间，也可以使用额外空间保存0出现的坐标`
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
            unsigned int zz = 0;
            int m = matrix.size();
            if(m == 0) return;
            int n = matrix[0].size();
            for(int i = 0; i< m; i++) {
                for(int j = 0; j<n;j++) {
                    if(matrix[i][j] == 0) {
                        if(i == 0) {
                            zz |= 2;
                        } 
                        if(j == 0) {
                            zz |= 1;
                        }
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                        
                    }
                }
            }
            for(int i = 1; i< m; i++) {
                for(int j= 1; j< n; j++) {
                        if(matrix[i][0] == 0 || matrix[0][j] == 0)matrix[i][j] = 0;
                }
            }

            if((zz & 2) != 0) {
                for(int i =0 ;i < n; i++) {
                    matrix[0][i] = 0;
                }
            }

            if((zz & 1) != 0) {
                for(int i =0 ;i < m; i++) {
                    matrix[i][0] = 0;
                }
            }
    }
};
