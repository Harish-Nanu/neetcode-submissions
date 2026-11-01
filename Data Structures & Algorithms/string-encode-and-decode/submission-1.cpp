class Solution {
public:
    string encode(vector<string>& strs) {
        string ans;
        for(auto &m : strs){
            ans += m;
            ans += (char)0;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector <string> ans;
        string temp;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == (char)0){
                ans.push_back(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        return ans;
    }
};
