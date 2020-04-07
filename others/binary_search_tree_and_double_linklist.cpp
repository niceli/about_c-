/*输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。*/
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        stack<TreeNode*> s;
        mid(pRootOfTree,s);
        TreeNode *pre = NULL;
        TreeNode *tmp = NULL;
        while(!s.empty()){
            tmp = s.top();
            s.pop();
            tmp->right = pre;
            if(!s.empty()){
		tmp->left = s.top();
                pre = tmp;
            }else{
                tmp->left = NULL;
                break;
            }
        }
        return tmp;
    }
    void mid(TreeNode* r,stack<TreeNode*> &s){
	if(r){
	    mid(r->left,s);
            s.push(r);
            mid(r->right,s);
        }
    }
   
};
//method 2
class Solution {
public:
    TreeNode* head = NULL;
    TreeNode* pre = NULL;
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        g(pRootOfTree);
        return head;
    }
     void g(TreeNode*r){
        if(!r) return;
         g(r->left);
         if(!head){
	    head = r;
            head->left = NULL;
         }else{
             r->left = pre;
             pre->right = r;
         }
         pre = r;
         g(r->right);
        
    }
};
//method 3
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return NULL;
        TreeNode* p = pRootOfTree;
        get(pRootOfTree);
        while(p->left){
            p = p->left;
        }
        return p;
    }
    void get(TreeNode* r){
        if(!r) return;
        get(r->left);
        get(r->right);
        if(getleft(r)){
           r->left = getleft(r);
        	getleft(r)->right = r;
        }
        if(getright(r)){
            r->right = getright(r);
        	getright(r)->left = r;
        }
    }
    TreeNode* getleft(TreeNode* r){
        TreeNode *t = r->left;
        if(!t) return NULL;
        while(t->right){
            t = t->right;
        }
        return t;
    }
    TreeNode* getright(TreeNode* r){
        TreeNode *t = r->right;
        if(!t) return NULL;
        while(t->left){
            t = t->left;
        }
        return t;
    }
    
};
