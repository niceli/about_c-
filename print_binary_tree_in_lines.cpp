/*
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
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
        vector<vector<int> > Print(TreeNode* pRoot) {
        	vector<int> r;
            queue<TreeNode*> q;
            vector<vector<int>> v;
            if(pRoot == NULL) return v;
            q.push(pRoot);
            int count = 0,size =1;
            while(!q.empty()){
		TreeNode* tmp = q.front();
                r.push_back(tmp->val);
                q.pop();
                if(tmp->left){
                    q.push(tmp->left);
                    count++;
                }
                if(tmp->right){
                    q.push(tmp->right);
                    count++;
                }
                if(--size == 0){
					size = count;
                    count = 0;
                    v.push_back(r);
                    r.clear();
                }
            }
            return v;
            
        }
    
};
//method 2
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            queue<TreeNode*> q;
            vector<vector<int>> m;
            if(!pRoot) return m;
            q.push(pRoot);
            int c=1;
            int nc = 0;
            while(!q.empty()){
                vector<int> v;
                   nc = 0;
                while(c--){     
                    v.push_back(q.front()->val);
                    if(q.front()->left){
                        q.push(q.front()->left);
                        nc++;
                    }
                    if(q.front()->right){
                         q.push(q.front()->right);
                        nc++;
                    }
                    q.pop();
                }
                c = nc;
           	m.push_back(v);     
            }
            
            return m;
            
        }
    
};
//print in '之' style
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        stack<TreeNode*> b;
        stack<TreeNode*> a;
        vector<vector<int>> r;
        if(pRoot == NULL) return r;
        b.push(pRoot);
        while(!b.empty()){
            
            vector<int> d;
            while(!b.empty()){
                TreeNode *tmp = b.top();
                d.push_back(tmp->val);
                b.pop();
                if(tmp->left) a.push(tmp->left);
                if(tmp->right) a.push(tmp->right);
            }
            if(d.size()>0) r.push_back(d);
            vector<int>c;
            while(!a.empty()){
                TreeNode *tmp = a.top();
				c.push_back(tmp->val);
                a.pop();
                if(tmp->right) b.push(tmp->right);
                if(tmp->left) b.push(tmp->left);
                
            }
            if(c.size()>0) r.push_back(c);
        }
        return r;
    }
    
};
