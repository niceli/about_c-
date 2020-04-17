//https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
//记录方向，设置对应的起始点和下标变化
 vector<vector<int>> zigzagLevelOrder(TreeNode*root) {
        vector<vector<int>> v;
        if (!root) return v;
        queue<TreeNode*>q;
        q.push(root);
        bool o = true;
        while (!q.empty()) {
            int s = q.size();
            vector<int> v1 (s);
            int index = o ? 0 : s - 1;
            while (s--) {
                TreeNode * n = q.front();
                q.pop();
                v1[index] = n -> val;
                index = o ? index + 1 : index - 1;
                if (n -> left) {
                    q.push(n -> left);
                }
                if (n -> right) {
                    q.push(n -> right);
                }
            }
            v.push_back(v1);
            o = !o;
        }
        return v;
    }
