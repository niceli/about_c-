/*输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
*/
/*
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int>> r;
        vector<int> v;
        if(!root) return r;
        v.push_back(root->val);
        expectNumber-=root->val;
        add(root,expectNumber,v,r);
        return r;
       
    }
    void add(TreeNode* r,int n,vector<int> v,vector<vector<int>>&rr){
        if(r->left == NULL&&r->right == NULL&&n == 0) {
            rr.push_back(v);
			return;
        }
        if(r->left!=NULL&&n>=r->left->val){
            v.push_back(r->left->val);
            add(r->left,n-r->left->val,v,rr);
            v.erase(v.begin()+v.size()-1);
        }
        if(r->right!=NULL&&n>=r->right->val){
            v.push_back(r->right->val);
            add(r->right,n-r->right->val,v,rr);
        }
    }
    
};
