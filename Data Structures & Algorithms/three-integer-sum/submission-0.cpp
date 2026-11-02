class Solution {
public:

    string make(vector <int>& temp){
        string ans;
        for(auto &m : temp){
            ans += to_string(m) + '|';
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map <int, bool> mp;
        int n = nums.size();
        vector <vector <int>> ans;
        unordered_map <string, bool> trip;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(mp.find(-nums[i]-nums[j]) != mp.end()){
                    vector <int> temp = {nums[i], nums[j], -nums[i]-nums[j]};
                    sort(temp.begin(), temp.end());
                    string str = make(temp);
                    if(trip.find(str) != trip.end()){
                        continue;
                    }
                    else{
                        trip[str] = true;
                    }
                    ans.push_back(temp);
                }
            }
            mp[nums[i]] = true;
        }
        return ans;
    }
};
