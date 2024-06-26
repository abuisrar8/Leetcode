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
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<TreeNode*> nodes;
        sorted(root, nodes); 
        return balance(nodes, 0, nodes.size() - 1);   
    }

private:
    void sorted(TreeNode* root, vector<TreeNode*>& nodes) {
        if (root == nullptr) return;
        sorted(root->left, nodes);
        nodes.push_back(root);
        sorted(root->right, nodes);
    }

    TreeNode* balance(vector<TreeNode*>& nodes, int l, int r) {
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* root = nodes[mid];
        root->left = balance(nodes, l, mid - 1);
        root->right = balance(nodes, mid + 1, r);
        return root;
    }
};
