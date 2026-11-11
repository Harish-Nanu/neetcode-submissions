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
    bool ans = true;

    int depth(TreeNode* root){
        if(!root){
            return 0;
        }
        int l = depth(root->right);
        int r = depth(root->left);
        if(abs(l - r) > 1){
            ans = false;
        }
        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        depth(root);
        return ans;
    }
};
