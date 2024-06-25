/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   
    TreeNode* bstToGst(TreeNode* root) {
        int sum =0;
        btog(root,sum);
        return root;   
    }
    void btog(TreeNode* root,int &sum)
    {
        if(root == nullptr)     return;
        btog(root->right,sum);
        sum+=root->val;
        root->val = sum;
        btog(root->left,sum);
    }

};
