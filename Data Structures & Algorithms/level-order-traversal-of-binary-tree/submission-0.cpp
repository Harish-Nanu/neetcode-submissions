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

    void traversal(TreeNode* root, vector <vector <int>>& order, int depth){
        if(!root){
            return;
        }
        if(depth >= order.size()){
            vector <int> temp = {root->val};
            order.push_back(temp);
        }
        else{
            order[depth].push_back(root->val);
        }
        traversal(root->left, order, depth+1);
        traversal(root->right, order, depth+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> order;
        traversal(root, order, 0);
        return order;
    }
};
