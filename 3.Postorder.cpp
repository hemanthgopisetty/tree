/**
 * 
 * 
 * Preorder Traversal 
 * left 
 * right 
 * root
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
    void postorder(TreeNode* root){
        if(root==nullptr){
            return ;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" -> ";
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
    sol.postorder(root);
    return 0;
}

/**
 *                (1)
 *               /   \
 *             (2)    (3)
 *            /   \     \
 *           (4)  (5)    (6)
 * 
 * find the post order traversal for the give binary tree
 * 
 * 4->5->2->3->6->1
 * 
 * start
 * if(!root) end
 * root
 * left subtree 
 * right subtree
 * repeat
 */