class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> st;
        for(auto &num : nums){
            st.insert(num);
        }
        if(nums.empty()){
            return 0;
        }
        int ans = 1, mx = 1;
        vector <int> uniq(st.begin(), st.end());
        for(int i = 1; i < uniq.size(); i++){
            if(uniq[i]-1 != uniq[i-1]){
                mx = max(ans, mx);
                ans = 1;
            }
            else{
                ans++;
            }
        }
        mx = max(mx, ans);
        return mx;
    }
};
