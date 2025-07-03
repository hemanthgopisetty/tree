/**
 * check wether both thre trees same or not
 */

 #include <bits/stdc++.h>
 using namespace std;
class TreeNode{
    public :
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Solution{
    public :
    bool isSameTree(TreeNode*p,TreeNode*q)
    {
        if(p==nullptr && q==nullptr)return true ;
        if(p==nullptr or q==nullptr)return false;

        if(p->val==q->val)return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);

        return false;

    }
};
 int main()
 {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right= new TreeNode(3);
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right= new TreeNode(3);
    Solution sol;
    bool result = sol.isSameTree(p,q);
    cout<<boolalpha<<result<<endl;
    return 0;
 }
 /**
  * 
  * recursively traverse both the nodes of three
  * if any of the case differs the solution then at that point just return the 
  * boolean based on the case
  */