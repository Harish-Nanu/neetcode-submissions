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

    int ans;

    int traverse(TreeNode* root, int k, int sof){
        int before = sof;
        if(!root){
            return 0;
        }
        int left = traverse(root->left, k, sof);
        before += left + 1;
        if(before == k){
            ans = root->val;
        }
        int right = traverse(root->right, k, before);
        return left + right + 1;

    }

    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k, 0);
        return ans;
    }
};
