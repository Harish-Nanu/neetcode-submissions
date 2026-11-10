class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        unordered_map <char, char> match;
        match[')'] = '(';
        match['}'] = '{';
        match[']'] = '[';
        for(auto &m : s){
            if(m == '(' || m == '{' || m == '['){
                st.push(m);
            }
            else{
                if(st.empty() || st.top() != match[m]){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};
