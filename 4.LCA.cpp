/**
 * Given tree contains two nodes p and q 
 * find the longest common ancestor between of two nodes
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public :
    TreeNode * left;
    TreeNode * right;
    int val;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){

    }

};


class Solution {
    public :
    TreeNode* longestCommonAncestor(TreeNode* root,TreeNode*p,TreeNode*q){
        if(root==nullptr or root==p or root ==q)return root;
        
        TreeNode* l = longestCommonAncestor(root->left,p,q);
        TreeNode* r = longestCommonAncestor(root->right,p,q);

        //if we found l and r ,it means 
        //both l and r in diff subtree's
        //return root as lca
        if(l and r)return root;

        //if any of the l or r null then return l or r if it's true or none
        if(l!=nullptr)return l;
        if(r!=nullptr)return r;
        return nullptr ;
    }
};


 int main(){
    TreeNode* root;
    root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left= new TreeNode(6);
    root->left->right= new TreeNode(2);
    root->right->left= new TreeNode(0);
    root->right->right= new TreeNode(8);
    root->left->right->left= new TreeNode(7);
    root->left->right->right= new TreeNode(4);
    Solution sol;
    
    TreeNode* lca = sol.longestCommonAncestor(root,root->left->right,root->left->right->right);
    if(lca){
        cout<<"LCA -> "<<lca->val;
    }
    else{
        cout<<"No Lca found";
    }
    return 0;
 }

 /*
 
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4



 If two nodes are in Same Sub Tree then one node is itsef LCA
 If two nodes are in diff sub Tree then root of the current node is LCA
 
 
 
 */