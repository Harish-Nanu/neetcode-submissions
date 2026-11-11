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
    int mx = 0;

    int depth(TreeNode* root){
        if(!root){
            return 0;
        }
        int l = depth(root->left), r = depth(root->right);
        mx = max(mx, l + r + 1);
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return mx-1;
    }
};
