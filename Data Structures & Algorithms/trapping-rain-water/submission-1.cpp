class Solution {
public:
    int trap(vector<int>& height) {
        stack <int> st;
        int n = height.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int mx = 0, ind = i;
            while(!st.empty() && (height[i] > height[st.top()])){
                ans += (height[i] - height[st.top()]);
                mx = height[st.top()];
                ind = st.top();
                st.pop();
                if(!st.empty()){
                    ans += (ind - st.top() - 1) * (height[i] - mx);
                }
            }
            if(st.empty()){
                ans -= (height[i] - mx) * (i - ind);
            }
            else{

            }
            st.push(i);
        }
        return ans;
    }
};
