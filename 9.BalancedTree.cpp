/**
 * 
 * Determine the tree is balanced or not
 * 
 * Balanced Tree:= Depth of two subtrees of every node 
 * never differs by more than one
 * 
 */
#include<bits/stdc++.h>
using namespace std;
const int RED_FLAG=-1;
class TreeNode{
    public :
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Solution{
    public :
    // int depth(TreeNode* root){
    //     if(root==nullptr)return 0;
    //     int left = depth(root->left);
    //     int right = depth(root->right);
    //     return max(left,right)+1;
    // }
    // bool isBalanced(TreeNode* root) {
    //     if(root==nullptr)return true;
    //     int left = depth(root->left);
    //     int right  = depth(root->right);
    //     return abs(left-right)<=1 && isBalanced(root->left) && isBalanced(root->right); 
    // }
    int depth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = depth(root->left);
        if (left == RED_FLAG)
            return RED_FLAG;
        int right = depth(root->right);
        if (right == RED_FLAG)
            return RED_FLAG;
        if (abs(left - right) > 1)
            return RED_FLAG;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root){
        return depth(root)!=RED_FLAG;
    }
     
};
int main()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol ;
    bool result = sol.isBalanced(root);
    cout<<boolalpha<<result<<endl;
    return 0;
} 

/**
 * 
 * balanced binary tree -> difference between height of two subtrees
 *                         are not bigger than 1
 * 
 * For each node
 *  find depth of the left subtree
 *      and right subtree
 *  check diff >1 if true return false else true
 *  repeat this for each node 
 * 
 *     int depth(TreeNode* root){
        if(root==nullptr)return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;
        int left = depth(root->left);
        int right  = depth(root->right);
        return abs(left-right)<=1 && isBalanced(root->left) && isBalanced(root->right); 
    } 

    height of the empty balanced tree is zero
    and empty  tree is balanced 
    this is the base case
    since for empty tree the difference between
    two nodes is less that 1 
    so it's balanced tree

    for each node we are calculating the depth 
    of the both subtree's 
    and checking absoluteness if it's less than 1 then 
    checkiing balanced tree for left
    repeating this for all nodes

    we can see there is lot redudant calculations
    depth performs traversal and balacned performs traversal
    depth of l takes O(n_L) time
    depth of r takes O(n_R) time
    isBal of l takes O(n_L) time
    isBal of r takes O(n_R) time

    T.C ->  O(n^2)


    to reduce this redudant calls we can just check 
    if any subtree height is not absolute return red flag

    if we reuturn red flag means then tree is not ballanced

    T.c -> O(n)
 */