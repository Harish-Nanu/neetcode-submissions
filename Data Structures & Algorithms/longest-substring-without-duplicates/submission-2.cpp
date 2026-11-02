class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        unordered_map <char, int> mp;
        int l = 0, r = 0, mx = 0, n = s.size();
        while(r < n){
            if(mp.find(s[r]) == mp.end()){
                mp[s[r]] = r;
                mx = max(r-l+1, mx);
                r++;
            }
            else{
                mp.erase(s[l]);
                l++;
            }
            if(r >= n){
                break;
            }
        }
        return mx;
    }
};
