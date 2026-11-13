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

    int traverse(TreeNode* root, int mx){
        if(!root){
            return 0;
        }
        return (int)(mx <= root->val) + traverse(root->right, max(mx, root->val)) + traverse(root->left, max(mx, root->val));
    }

    int goodNodes(TreeNode* root) {
        int mx = -101;
        return traverse(root, mx);
    }
};
