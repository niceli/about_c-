//https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
//1 先序遍历存储，然后展开
//2 递归处理右，并记录尾，更新左的时候设置尾

vector<TreeNode*>v;
void buid(TreeNode*root){
    if(root){
        v.push_back(root);
        buid(root->left);
        buid(root->right);
    }
}

void flatten(TreeNode*root){
    if(!root)return;
    buid(root);
    TreeNode*h=v[0];
    for(int i=1;i<v.size();i++){
        v[i]->left=NULL;
        v[i]->right=NULL;
        h->right=v[i];
        h=v[i];
    }
    v[0]->left=NULL;
}

TreeNode* fl(TreeNode* root, TreeNode* t) {
    TreeNode* tmp = t;
    if(root->right) {
		tmp = fl(root->right, t);
	}

	if(root->left) {
		root->right = fl(root->left, tmp);
	}else {
		root->right = tmp;
	}
    root->left = NULL;
	return root;
}

 void flatten(TreeNode* root) {
 	if(!root) return;
 	fl(root, NULL);

 }
