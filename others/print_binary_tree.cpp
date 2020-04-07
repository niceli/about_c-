/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    vector<int> PrintFromTopToBottom(TreeNode *root) {
		vector<int> v;
        queue<TreeNode*> q;
        if(!root) return v;
        q.push(root);
        TreeNode *tmp;
        while(!q.empty()){
            tmp = q.front();
            v.push_back(tmp->val);
            q.pop();
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        return v;
    }
};
