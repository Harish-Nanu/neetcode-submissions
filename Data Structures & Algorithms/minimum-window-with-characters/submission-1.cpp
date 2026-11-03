class Solution {
public:

int ARR_SIZE = ('z' - 'A') + 1;

    bool match(vector <int>& fq1, vector <int>& fq2){
        for(int i = 0; i < ARR_SIZE; i++){
            if(fq1[i] < fq2[i]){
                return false;
            }
        }
        return true;
    }

    int check(string& s, vector <int>& fq, int mid){
        vector <int> f(ARR_SIZE);
        for(int i = 0; i < mid; i++){
            f[s[i] - 'A']++;
        }
        for(int i = mid; i < s.size(); i++){
            if(match(f, fq)){
                return i - mid;
            }
            f[s[i - mid] - 'A']--;
            f[s[i] - 'A']++;
        }
        if(match(f, fq)){
            return s.size() - mid;
        }
        return -1;
    }

    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        // return to_string(ARR_SIZE);
        if(m > n){
            return "";
        }
        vector <int> fq(ARR_SIZE);
        for(auto &ch : t){
            fq[ch - 'A']++;
        }
        int l = -1, r = n+1, mid, idx = -1;
        while(l + 1 < r){
            mid = l + (r - l) / 2;
            int curr = check(s, fq, mid);
            if(curr >= 0){
                r = mid;
                idx = curr;
            }
            else{
                l = mid;
            }
        }
        if(idx == -1){
            return "";
        }
        return s.substr(idx, r);
    }
};
