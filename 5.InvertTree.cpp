/**
 *
 * Give Binary tree, return inverted binary tree
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
class Solution
{
private:
public:
    TreeNode *iterative(TreeNode *root, queue<TreeNode *> &q)
    {
        if(root==nullptr)return root ;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(!cur)continue;
            if(cur->left!=nullptr)q.push(cur->left);
            if(cur->right!=nullptr)q.push(cur->right);
            swap(cur->left,cur->right);
        }
        return root;
    }
    TreeNode *iterative(TreeNode *root, stack<TreeNode *> &stk)
    {
        if (root == nullptr)
            return root;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *cur = stk.top();
            stk.pop();
            if (!cur)
                continue;
            if (cur->left != nullptr)
                stk.push(cur->left);
            if (cur->right != nullptr)
                stk.push(cur->right);
            swap(cur->left, cur->right);
        }
        return root;
    }
    TreeNode *recurs(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        swap(root->left, root->right);
        recurs(root->left);
        recurs(root->right);
        return root;
    }
    TreeNode *invertTree(TreeNode *root)
    {
        // return recurs(root);
        stack<TreeNode *> stk;
        // return iterative(root,stk);
        queue<TreeNode *> q;
        return iterative(root, q);
    }
};
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    Solution sol;
    root = sol.invertTree(root);
    return 0;
}

/*

4,2,7,1,3,6,9

    TreeNode* recurs(TreeNode* root){
        if(root==nullptr)return root ;
        swap(root->left,root->right);
        recurs(root->left);
        recurs(root->right);
        return root;
    }

    swap current node pointers and val
    recurs left and right
    until root is not null
    Time Complexity :- O(n)
    Space Compleity :- O(h)
    h -> height of the tree
    n -> no of nodes in tree



        Iterative DFS
        TreeNode* iterative(TreeNode*root){
        if(root==nullptr)return root;
        stack<TreeNode*> stk ;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode* cur = stk.top();
            stk.pop();
            if(!cur)continue;
            if(cur->left!=nullptr)stk.push(cur->left);
            if(cur->right!=nullptr)stk.push(cur->right);
            swap(cur->left,cur->right);
        }
        return root ;
    }
    Tc : O(n) , n -> no of nodes in the tree
    Sc : O(h) , h -> height of the tree

    Breadth First Search
    TreeNode *iterative(TreeNode *root, queue<TreeNode *> &q)
    {
        if(root==nullptr)return root ;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(!cur)continue;
            if(cur->left!=nullptr)q.push(cur->left);
            if(cur->right!=nullptr)q.push(cur->right);
            swap(cur->left,cur->right);
        }
        return root;
    }
    Tc : O(n) , n -> no of nodes in the tree
    Sc : O(w) , h -> height of the tree
*/