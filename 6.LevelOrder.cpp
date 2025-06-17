/**
 *
 * Given Tree , Traverse the tree in level
 */

#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public :
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Solution{
    private:
    public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
    }
};
int main(){
    TreeNode* root  = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right= new TreeNode(20);
    root->right->left= new TreeNode(15);
    root->right->right= new TreeNode(7);
    Solution sol;
    vector<vector<int>>res = sol.levelOrder(root);
    for(int i=0;i<(int)res.size();i++)
    {
        cout<<"[";
        for(int j=0;j<(int)res[i].size();i++)
        {   
            cout<<res[i][j];
            if(i<res.size()-1)cout<<", ";
        }
        cout<<"]  "<<endl;
    }
    return 0;
}

/**
 * [3,9,20,null,null,15,7]
 *             3
 *           /   \
 *          9     20
 *               /  \
 *              15   7
 */