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
    bool check(TreeNode* org, TreeNode* sub){
        if(!org && sub){
            return false;
        }
        else if(org && !sub){
            return false;
        }
        else if(!org && !sub){
            return true;
        }
        else if(org->val != sub->val){
            return false;
        }
        return check(org->right, sub->right) && check(org->left, sub->left);
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root){
            return false;
        }
        if(check(root, subRoot)){
            // cout << root->val << endl;
            return true;
        }
        else{
            return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
        }
    }
};
