/**
 * Given tree contains two nodes p and q 
 * find the longest common ancestor between of two nodes
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public :
    TreeNode* longestCommonAncestor(TreeNode* root){
        if(root!=nullptr)return ;
        
    }
};
class TreeNode{
    public :
    TreeNode * left;
    TreeNode * right;
    int val;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}

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
    
    TreeNode* lca = sol.longestCommonAncestor(root);
    if(lca){
        cout<<"LCA -> "<<lca->val;
    }
    else{
        cout<<"No Lca found";
    }
    return 0;
 }