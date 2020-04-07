/*
请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定
义其为对称的。
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
    	stack<TreeNode*> a;
        stack<TreeNode*> b;
        if(!pRoot) return true;
        if(!pRoot->left&&!pRoot->right) return true;
        if(!pRoot->left||!pRoot->right) return false;
        a.push(pRoot->left);
        b.push(pRoot->right);
        while(!a.empty()&&!b.empty()){
			TreeNode* ta = a.top();
            a.pop();
            TreeNode* tb = b.top();
            b.pop();
            if(ta->val!=tb->val) return false;
            if(ta->right&&tb->left){
                a.push(ta->right);
                b.push(tb->left);
            }else if(ta->right||tb->left){
                return false;
            }
            if(ta->left&&tb->right){
                a.push(ta->left);
                b.push(tb->right);
            }else if(ta->left||tb->right){
                return false;
            }
        }
        if(!a.empty()||!b.empty()) return false;
        return true;
        
    }

};
//method 2
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot) return true;
    	return compare(pRoot->left,pRoot->right);
        
    }
    bool compare(TreeNode*l,TreeNode*r){
        if(l&&r){
            if(l->val == r->val){
                return compare(l->right,r->left)&&compare(l->left,r->right);
            }else{
                return false;
            }
        }else if(l||r){
            return false;
        }
        return true;
    }

};
