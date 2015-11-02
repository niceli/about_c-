/*
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经
过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
:递归求，每次保留左右子树最长的那个深度。
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
    	int n = 0;
        return get(pRoot,n);
    }
    int get(TreeNode* r,int n){
        if(r == NULL) return n;
        n++;
        if(r->left==NULL&&r->right == NULL){
			return n;
        }
        else{
            if(get(r->left,n)>get(r->right,n)){
                return get(r->left,n);
            }else{
                return get(r->right,n);
            }
        }
    }
};
