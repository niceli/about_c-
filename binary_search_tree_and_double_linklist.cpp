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
