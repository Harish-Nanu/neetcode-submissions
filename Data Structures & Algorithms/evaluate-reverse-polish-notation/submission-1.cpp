class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(auto &ch : tokens){
            if(ch == "+"){
                int second_num = st.top();
                st.pop();
                int first_num = st.top();
                st.pop();
                int num = first_num + second_num;
                st.push(num);
            }
            else if(ch == "-"){
                int second_num = st.top();
                st.pop();
                int first_num = st.top();
                st.pop();
                int num = first_num - second_num;
                st.push(num);
            }
            else if(ch == "*"){
                int second_num = st.top();
                st.pop();
                int first_num = st.top();
                st.pop();
                int num = first_num * second_num;
                st.push(num);
            }
            else if(ch == "/"){
                int second_num = st.top();
                st.pop();
                int first_num = st.top();
                st.pop();
                int num = first_num / second_num;
                st.push(num);
            }
            else{
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};
