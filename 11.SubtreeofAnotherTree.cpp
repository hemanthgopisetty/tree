/***
 * 
 * 
 * Find subtree q in the given tree p 
 * 
 * the tree could be considered is a substree it self
 *  
 * 
 */
#include <bits/stdc++.h>
using namespace std;
class TreeNode{
    public :
    int val ;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Solution{
    public :
    bool isSubTree(TreeNode* p ,TreeNode* q){
        if(!p) return false ;

        if(isSameTree(p,q))return true;

        return isSubTree(p->left,q) or isSubTree(p->right,q);
    }   

    bool isSameTree(TreeNode* p,TreeNode* q){
        if(!p or !q)return p==nullptr and q==nullptr;

        if(p->val==q->val)return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);

        return false ;
    }
};
int main()
{
    TreeNode* p = new TreeNode(3);
    p->left = new TreeNode(4);
    p->right = new TreeNode(5);
    p->left->left = new TreeNode(1);
    p->left->right = new TreeNode(2);
    p->right->left = new TreeNode(6);
     p->right->right = new TreeNode(7);

     
    //  p->right->left->left = new TreeNode(8);
    //  p->right->right->right = new TreeNode(9);

    TreeNode* q = new TreeNode(5);
    q->left = new TreeNode(6);
    q->right = new TreeNode(7);

    Solution sol;
    bool result = sol.isSubTree(p,q);
    cout<<boolalpha<<result<<endl;
    return 0;
}

/**
 * this question same as isSameTree which means checking both the tree are identical or not
 * but this question twists by checking substree in the given tree identical or not
 * 
 * for each node we have to check wether substree q is there or not
 * if it's there then return true or false
 * 
 * here each node reprsenta a subtree
 * so for each subtree check wether this subtree and given substree identical or not
 * 
 * and after this check for left substree in this node and right substree in this node 
 * 
 * this recursive search for identity gives the answer 
 * 
 * 
 * 
 */