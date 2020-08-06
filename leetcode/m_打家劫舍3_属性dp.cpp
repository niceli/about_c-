//https://leetcode-cn.com/problems/house-robber-iii/

//method 1
unordered_map<TreeNode*, int> g,f;
void dfs(TreeNode* t) {
	if(!t) return;
	dfs(t->left);
	dfs(t->right);
	f[t] = g[t->left] + g[t->right] + t->val;
	g[t] = max(f[t->left], g[t->left]) + max(f[t->right], g[t->right]);
}

int rob(TreeNode* root) {
	g.clear();
	f.clear();
	dfs(root);
	return max(g[root], f[root]);
}



//method 2   first: choose_max,  second:not_choose_max
pair<int,int> dfs1(TreeNode* t) {
	if(!t) return {0, 0};
	auto tl = dfs1(t->left);
	auto tr = dfs1(t->right);
	return {t->val + tl.second + tr.second, max(tl.first, tl.second) + max(tr.first, tr.second)};
}

int rob1(TreeNode* root) {
	auto z = dfs1(root);
	return max(z.first, z.second);
}
