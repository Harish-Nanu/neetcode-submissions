class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector <string> cp = strs;
        for(int i = 0; i < n; i++){
            sort(cp[i].begin(), cp[i].end());
        }
        vector <int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int x, int y){
            return cp[x] > cp[y];
        });
        vector <vector <string>> ans;
        vector <string> temp = {strs[idx[0]]};
        for(int i = 1; i < n; i++){
            if(cp[idx[i]] != cp[idx[i-1]]){
                ans.push_back(temp);
                temp = {strs[idx[i]]};
            }
            else{
                temp.push_back(strs[idx[i]]);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
