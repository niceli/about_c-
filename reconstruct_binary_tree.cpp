/**
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的
前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列
{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
		if(pre.size() == 0||in.size() == 0) return NULL;
        int a = pre[0];
        TreeNode* head = new TreeNode(a);
        vector<int> p1,p2,m1,m2;
        int i=0;
        for(;i<in.size()&&in[i]!=a;i++){
			m1.push_back(in[i]);
        }
        for(++i;i<in.size();i++){
			m2.push_back(in[i]);
        }
        int j=1;
        for(;j<m1.size()+1;j++){
			p1.push_back(pre[j]);
        }
        for(;j<pre.size();j++){
            p2.push_back(pre[j]);
        }
        head->left = reConstructBinaryTree(p1,m1);
        head->right = reConstructBinaryTree(p2,m2);
        return head;
        
    }
};
