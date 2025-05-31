/**
 * 
 * 
 * Preorder Traversal
 * root 
 * left 
 * right 
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
    void preorder(TreeNode* root){
        if(root==nullptr){
            return ;
        }
        cout<<root->val<<" -> ";
        preorder(root->left);
        preorder(root->right);
    }
};
int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    Solution sol;
    sol.preorder(root);
    return 0;
}

/**
 *                (1)
 *               /   \
 *             (2)    (3)
 *            /   \     \
 *           (4)  (5)    (6)
 * 
 * find the pre order traversal for the give binary tree
 * 
 * 1->2->4->5->3->6 
 * 
 * start
 * if(!root) end
 * root
 * left subtree 
 * right subtree
 * repeat
 */