//https://leetcode-cn.com/problems/clone-graph/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> s;
    Node* cloneGraph(Node* node) {       
        if(node == NULL) return NULL;
        //cout <<node->val<<endl;
        if(s.count(node->val) == 0) {
            Node* n = new Node(node->val);
            s[node->val] = n;
            for(auto x: node->neighbors) {
                n->neighbors.push_back(cloneGraph(x));
            }
            return n;
        } else {
            return s[node->val];
        }
    }
};
