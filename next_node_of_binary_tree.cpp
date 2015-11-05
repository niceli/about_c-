using namespace std;
/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode->right == NULL){          
            if(pNode->next == NULL) return NULL;
            if(pNode->next->left == pNode){
                return pNode->next;
            }else{
                while(pNode->next){					
                    if(pNode->next->next == NULL &&pNode->next->right == pNode){
                        return NULL;
                    }
                    pNode = pNode->next;
            	}
           		 return pNode;
            }
        }
        pNode = pNode->right;
        while(pNode->left){
            pNode = pNode->left;
        }
        return pNode;
    }
};
