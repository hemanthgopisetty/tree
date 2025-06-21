/***
 *
 *
 * Given root node , return max depth of the ree
 *
 * max depth -> number of nodes along the longest path
 * from the root node to down the farthest leaf node
 *
 */

#include <bits/stdc++.h>

using namespace std;
class TreeNode
{
    public :
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
    public :
    int maxDepth(TreeNode*root){
        if(!root)return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return max(l,r)+1;
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
    int result = sol.maxDepth(root);
    cout<<result <<endl;
    return 0;
}