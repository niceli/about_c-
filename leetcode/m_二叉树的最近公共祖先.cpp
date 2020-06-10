//https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution {
public:

    TreeNode* find(TreeNode* r, TreeNode* a, TreeNode* b) {
        if(!r) return NULL;
        if(r == a || r == b) return r;
        TreeNode* l = find(r->left, a, b);
        TreeNode* tr = find(r->right, a, b);
        if( l && tr) return r;
        if(l || tr) return l ? l : tr; //回溯过程中 确认的点 不能变 
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == q) return p;
        return find(root, p, q);
    }
};
