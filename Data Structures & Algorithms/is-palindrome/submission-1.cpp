class Solution {
public:
    bool isPalindrome(string s) {
        string pre = "";
        for(auto &ch : s){
            if(ch >= 'a' && ch <= 'z'){
                pre += ch;
            }
            else if(ch >= '0' && ch <= '9'){
                pre += ch;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                pre += ch + ('a' - 'A');
            }
            else{
                continue;
            }
        }
        int n = pre.size();
        for(int i = 0; i <= n/2; i++){
            if(pre[i] != pre[n - i - 1]){
                return false;
            }
        }
        return true;
    }
};
