/**
 * Convert the sorted array into binary search tree
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

private:
};
class Solution
{
public:
    void printTree(TreeNode *root)
    {
        if (!root)
        {
            cout << "null\n";
            return;
        }
        cout << root->val << endl;
        printTree(root->left);
        printTree(root->right);
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildBst(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *buildBst(vector<int> &nums, int left, int right)
    {

        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode *root = new TreeNode(nums[mid]);

        root->left = buildBst(nums, left, mid - 1);
        root->right = buildBst(nums, mid + 1, right);

        return root;
    }
};
int main()
{
    vector<int>nums{-10,-3,0,5,9};
    Solution sol;
    TreeNode *ans = sol.sortedArrayToBST(nums);
    return 0;
}
/**
 * Balanced BST
 * Properties of Binary Search Tree
 *
 * root.right is greater than the root.value
 * root.left is lesser than the root.value
 *
 * based on these principles we will constrcut the tree
 * recusrively
 *
 * since array is sorted we will take the mid element
 * and the left half which is mid-1 and the right half which is mid+1
 * will be the subtree's
 *
 * we will follow the same thing for all other valuess
 * since we access the element at least once
 * the time complexity is O(N)
 *
 *
 *
 *
 *
 */