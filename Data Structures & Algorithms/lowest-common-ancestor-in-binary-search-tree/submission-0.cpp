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
    int ind = 1;
    vector<vector<TreeNode*>> up{101, vector<TreeNode*>(11, nullptr)};
    vector<int> depth = vector<int>(101, 0);
    unordered_map <TreeNode*, int> idx;

    void fillup(TreeNode* root, TreeNode* par, int dep){
        if(!root){
            return;
        }
        idx[root] = ind;
        up[ind][0] = par;
        for(int num = 1; num < 11; num++){
            TreeNode* mid = up[ind][num-1];
            up[ind][num] = (mid == nullptr) ? nullptr : up[idx[mid]][num-1];
        }
        depth[ind] = dep;
        ind++;
        fillup(root->right, root, dep+1);
        fillup(root->left, root, dep+1);
    }

    TreeNode* get_ancestor(TreeNode* root, int level){
        if(!root){
            return NULL;
        }
        if(level > depth[idx[root]]){
            return NULL;
        }
        TreeNode* curr = root;
        int num = 0;
        while(level > 0){
            if(level&1){
                curr = up[idx[curr]][num];
            }
            num++;
            level >>= 1;
        }
        return curr;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        idx[root] = 0;
        fillup(root->left, root, 1);
        fillup(root->right, root, 1);
        TreeNode* ans = nullptr;
        depth[0] = 0;
        int ldept = depth[idx[p]], rdept = depth[idx[q]];
        if(ldept < rdept){
            int dif = rdept - ldept;
            q = get_ancestor(q, dif);
        }
        else if(ldept > rdept){
            int dif = ldept - rdept;
            p = get_ancestor(p, dif);
        }
        int l = -1, r = ldept+1, mid;
        while(l + 1 < r){
            mid = l + (r - l) / 2;
            TreeNode* panc = get_ancestor(p, mid);
            TreeNode* qanc = get_ancestor(q, mid);
            if(panc == qanc){
                r = mid;
                ans = qanc;
            }
            else{
                l = mid;
            }
        }
        return ans;
    }
};
