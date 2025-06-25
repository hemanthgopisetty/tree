/***
 *
 * find the diameter of the given binary tree
 *
 *
 */

#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution{
    public :
    int maxDiameter=0;
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root);
    }
    private :
    int dfs(TreeNode* root){
        
        if(!root)return 0;
        int l = dfs(root->left);//this gives the height of the left subtree
        int r = dfs(root->right);//this gives the height of the right subtree

        //this maxDiameter stores and compares the current no of edges
        //i.e left height and right height subtree
        //combined 
        maxDiameter=max(maxDiameter,l+r+1);


        return max(l,r)+1;//returns tallest height of the subtree
    }
};
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right=new TreeNode(7);
    

    Solution sol ;
    int result  = sol.diameterOfBinaryTree(root);
    cout<<result<<endl;
    return 0;
}

/**
 * 
 * 
 * Height of a binary tree
 * 
 *  length of the longest path from the root node to any leaf node in tree
 *  It tells how tall the tree is from root node 
 *  Typically Measures in terms of no of edges 
 *  from the root to deepest leaf
 * 
 * 
 * 
 * Diameter of Binary Tree
 *  length fo the longest path between any two nodes in the tree
 *  these two nodes do not have to be leaf nodes , 
 *  Global Measurement -> longest stretch or widest across the enitre tree
 *          regardless where the tree is root is postined 
 *          relative to that path
 * 
 * we will calculate the max height at every node 
 * because at each node we are calculating how many 
 * edges current node is having right
 * 
 * 
 * recursively calculating no of edges that each node has 
 * and keeping that calculation in global , give again , 
 * to calculate max the current diameter and global maax
 * compare and give that's the diameter
 * 
 * since we need to calculate the diameter 
 * and that diameter is defined as 
 * length of the longest path between two nodes
 * in a tree ,that may or may not pass through the root
 * 
 * and the length of path is nothing no of edges between two nodes 
 * that nodes can by anywhere that can leaf or middle or root 
 * what ever it can 
 */