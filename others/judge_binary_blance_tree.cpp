/*输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        bool s = true;
        deep(pRoot,s);
        return s;
    }
    int deep(TreeNode* r,bool &s){
        if(!r) return 0;
        int a = deep(r->left,s);
        int b = deep(r->right,s);
        if(a-b>1||b-a>1) s = false;
        return max(1+a,1+b);
    }
};
