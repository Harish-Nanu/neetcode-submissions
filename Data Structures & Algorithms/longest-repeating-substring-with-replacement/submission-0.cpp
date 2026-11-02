class Solution {
public:
    int process(vector <int> freq){
        sort(freq.begin(), freq.end(), greater <int>());
        int sum = 0;
        for(int i = 1; i < 26; i++){
            sum += freq[i];
            if(!freq[i]){
                break;
            }
        }
        return sum;
    }

    bool check(string& s, int leng, int k){
        int n = s.size();
        vector <int> freq(26);
        for(int i = 0; i < leng; i++){
            freq[s[i] - 'A']++;
        }
        if(process(freq) <= k){
            return true;
        }
        for(int i = leng; i < n; i++){
            freq[s[i - leng] - 'A']--;
            freq[s[i] - 'A']++;
            if(process(freq) <= k){
                return true;
            }
        }
        return false;
    }

    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0;
        int l = 0, r = n+1, mid;
        while(l + 1 < r){
            mid = l + (r-l) / 2;
            if(check(s, mid, k)){
                ans = mid;
                l = mid;
            }
            else{
                r = mid;
            }
        }
        return l;    
    }
};
