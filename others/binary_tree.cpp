#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
vector<int> l;
class Node
{
public:
    int v;
    bool t = false;
    Node *l;
    Node *r;
    Node(int v){
        this->v = v;
        l = NULL;
        r = NULL;
    }
    Node(){
        l = NULL;
        r = NULL;
    }
};
void getelement(){
    int t;
    while (cin>>t) {
        l.push_back(t);
    }
}
Node * getTree(int n){
    Node* tmp;
    if (n<l.size()) {
        tmp = new Node(l[n]);
        tmp->l = getTree(2*n+1);
        tmp->r = getTree(2*n+2);
    }else{
        return NULL;
    }
    return tmp;
}
void fshow(Node *root){
    if(root!=NULL){
        cout<<root->v<<" ";
        fshow(root->l);
        fshow(root->r);
    }
}
void f(Node* root){
    stack<Node*> s;
    if (root!=NULL) {
        s.push(root);
    }
    while (!s.empty()) {
        Node* tmp = s.top();
        s.pop();
        cout<<tmp->v<<" ";
        if(tmp->r){
            s.push(tmp->r);
        }
        if(tmp->l){
            s.push(tmp->l);
        }
    }
}
void mshow(Node* root){
    if (root!=NULL) {
        mshow(root->l);
        cout<<root->v<<" ";
        mshow(root->r);
    }
}
void m(Node* root){
    stack<Node*> s;
    if (root!= NULL) {
        s.push(root);
    }
    while (!s.empty()) {
        Node* tmp = s.top();
        while (tmp->l&&!tmp->l->t) {
            tmp = tmp->l;
            s.push(tmp);
        }
        cout<<tmp->v<<" ";
        tmp->t = true;
        s.pop();
        if (tmp->r&&!tmp->r->t) {
            s.push(tmp->r);
        }
        
    }
}
void mid(Node* root){
  if(root == NULL) return;
  Node p = root;
  stack<Node*> s;
  while(p!=NULL||!s.empty()){
   while(p!=NULL){
    s.push(p);
    p = p->left;
   }
   cout<< s.top();
   s.pop();
   p = p->right;
  }
}
void bshow(Node* root){
    if(root!=NULL){
        bshow(root->l);
        bshow(root->r);
        cout<<root->v<<" ";
    }
}
void b(Node* root){
    stack<Node*> s;
    if (root!=NULL) {
        s.push(root);
    }
    while (!s.empty()) {
        Node* tmp = s.top();
        while (tmp->l&&!tmp->l->t) {
            tmp = tmp->l;
            s.push(tmp);
        }
        if (tmp->r&&!tmp->r->t) {
            
            s.push(tmp->r);
        }
        if(!tmp->r||tmp->r->t){
            tmp->t = true;
            cout<<tmp->v<<" ";
            s.pop();
        }
    }
}
void deep(Node *r){
    stack<Node*> s;
    s.push(r);
    while (!s.empty()) {
        Node* tmp = s.top();
        cout<<tmp->v<<" ";
        s.pop();
        if(tmp->r) s.push(tmp->r);
        if(tmp->l) s.push(tmp->l);
    }
}
void guang(Node* r){
    queue<Node*> q;
    if(r == NULL){
        return;
    }
    q.push(r);
    while (!q.empty()) {
        Node* tmp = q.front();
        cout<<tmp->v<<" ";
        q.pop();
        if(tmp->l) q.push(tmp->l);
        if(tmp->r) q.push(tmp->r);
    }
}
int main(){
    
    getelement();
    Node *root = getTree(0);
    cout<<"----"<<endl;
    mshow(root);
    cout<<endl;
    cout<<"---"<<endl;
    m(root);
    cout<<endl;
    cout<<"---"<<endl;
    deep(root);
    cout<<endl;
    cout<<"---"<<endl;
    guang(root);
    return 0;
}
