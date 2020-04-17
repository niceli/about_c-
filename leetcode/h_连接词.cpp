//https://leetcode-cn.com/problems/concatenated-words/
//词树

struct Node {
	int child[26] = {0}; //存节点的下标
	bool end = false;
	Node(bool ise): end(ise) {}
};
Node* root;
vector<Node*> v; //存节点

vector<string> ans;
bool find(string a, int f, int c) {
	Node* r = root;
	if(f == a.length() && c >= 2) {
		ans.push_back(a);
		return true;
	}

	bool fd = false;
	while(r && f < a.length() && !fd) {
		int idx = r->child[a[f] -'a'];
		if(idx) {
			Node* t = v[idx];
			if(t->end) {
				fd = find(a, f+1, c+1); 
			}
			r = t;
		} else {
			break;
		}
		f++;
	}

	return fd;
}

void build(string a) {
	Node* r  = root;
	int s = 0, len = a.length();
	while(s < len) {
		int idx = r->child[a[s] -'a'];
		if(!idx){
			Node* n = new Node(s == len -1);
			v.push_back(n);
			r->child[a[s] - 'a'] = v.size() -1;
			r = n;
		} else {
			if(s == len -1) {
				v[idx]->end = true;
			}
			r = v[idx];
		}
		s++;
	}
}

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
	root = new Node(false);
	v.push_back(root);
	for(auto word: words) build(word);
	for(auto word: words) find(word, 0, 0);
	return ans;
}





#include <bits/stdc++>
using namespace std;
struct Node {
	vector<Node*> child;
	int v;
	bool isF = false;
	Node(char c, bool isF): child(26, NULL), v(c - 'a'), isF(isF){}
};
Node* root;
vector<string> ans;
bool find(string a, int f, int c) {
	Node* r = root;
	if(f == a.length() && c >= 2) {
		ans.push_back(a);
		return true;
	}

	bool fd = false;
	while(r && f < a.length() && !fd) {
		Node* t = r->child[a[f] -'a'];
		if(t) {
			if(t->isF) {
				fd = find(a, f+1, c+1); 
			}
			r = t;
		} else {
			break;
		}
		f++;
	}

	return fd;
}

void build(string a) {
	Node* r  = root;
	int s = 0, len = a.length();
	bool nf = true;
	while(s < len) {
		Node* t = r->child[a[s] -'a'];
		if(!t){
			Node* n = new Node(a[s], s == len -1);
			r->child[a[s] - 'a'] = n;
			r = n;
		} else {
			if(t->isF && nf) {
				nf = !find(a, s+1, 1);
			}
			r = t;
		}
		s++;
	}
}

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
	sort(words.begin(), words.end(), [&](const string & a, const string &b) {
		return a.length() < b.length();
	});

	root = new Node('_', false);
	for(auto word: words) build(word);
	return ans;
}
