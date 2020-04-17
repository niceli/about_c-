//https://leetcode-cn.com/problems/01-matrix/
//动态规划  左上一次， 右下一次，更新为最小值
class Solution {
public:
int up[2][2] = {{0,-1}, {-1, 0}};
int dn[2][2] = {{0,1}, {1, 0}};
 vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
 		int n  = matrix.size();
 		if(n == 0) return matrix;
 		int m = matrix[0].size();

 		for(int i = 0; i< n;i ++) {
 			for(int j = 0; j< m; j++) {
 				if(matrix[i][j] == 0) continue;
 				matrix[i][j] = 100000;
 				for(auto [a, b]: up) {
 					int dx = a+i;
 					int dy = b+j;
 					if(dx >= 0 && dy>=0) {
 						matrix[i][j] = min(matrix[dx][dy] + 1, matrix[i][j]);
 					}
 				}
 			}
 		}

 		for(int i = n-1; i>=0; i--) {
 			for(int j = m-1; j>=0; j--) {
 				if(matrix[i][j] == 0) continue;
 				for(auto [a, b]: dn) {
 					int dx = a+i;
 					int dy = b+j;
 					if(dx <n && dy< m) {
 						matrix[i][j] = min(matrix[dx][dy] + 1, matrix[i][j]);
 					}
 				}
 			}
 		}

 		return matrix;
 }
};
