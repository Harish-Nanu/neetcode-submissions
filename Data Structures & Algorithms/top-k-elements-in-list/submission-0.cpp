class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> cnt;
        map <int,vector <int>, greater <int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            cnt[nums[i]]++;
        }
        for(auto &m : cnt){
            mp[m.second].push_back(m.first);
        }
        auto itr = mp.begin();
        vector <int> ans;
        int ct = 0;
        for(auto &m : mp){
            for(auto &num : m.second){
                ans.push_back(num);
                ct++;
                if(ct == k){
                    return ans;
                }
            }
        }
        return ans;
    }
};
