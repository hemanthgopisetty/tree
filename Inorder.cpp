/**
 * Inorder Traversal
 * -> depth first traversal
 * left substree
 * root node
 * right substree
 * 
 */

#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public :
    TreeNode * left;
    TreeNode * right;
    int val;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}

};
class Solution {
    public :
    void inorder(TreeNode* root){
        if(root==nullptr){
            return ;
        }
        inorder(root->left);
        cout<<root->val;
        inorder(root->right);
    }
};
int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    Solution sol;
    sol.inorder(root);
    return 0;
}