class Solution {
public:

    bool match(vector <int>& fq1, vector <int>& fq2){
        for(int i = 0; i < 26; i++){
            if(fq1[i] != fq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(m < n){
            return false;
        }
        vector <int> fq1(26), fq2(26);
        for(int i = 0; i < n; i++){
            fq1[s1[i] - 'a']++;
        }
        for(int i = 0; i < n; i++){
            fq2[s2[i] - 'a']++;
        }
        for(int i = n; i < m; i++){
            if(match(fq1, fq2)){
                return true;
            }
            fq2[s2[i - n] - 'a']--;
            fq2[s2[i] - 'a']++;
        }
        if(match(fq1, fq2)){
            return true;
        }
        return false;
    }
};
