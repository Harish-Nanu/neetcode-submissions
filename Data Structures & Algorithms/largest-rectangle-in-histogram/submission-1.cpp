class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack <int> st;
        vector <int> leftMin(n, -1), rightMin(n, n);
        for(int i = 0; i < n; i++){
            if(!st.empty()){
                while(!st.empty() && heights[st.top()] >= heights[i]){
                    st.pop();
                }
                if(!st.empty()){
                    leftMin[i] = st.top();
                }
            }
            st.push(i);
        }
        st = {};
        for(int i = n-1; i >= 0; i--){
            if(!st.empty()){
                while(!st.empty() && heights[st.top()] >= heights[i]){
                    st.pop();
                }
                if(!st.empty()){
                    rightMin[i] = st.top();
                }
            }
            st.push(i);
        }
        int mx = 0;
        for(int i = 0; i < n; i++){
            // cout << heights[i] << " " << leftMin[i] << " " << rightMin[i] << endl;
            mx = max(mx, (rightMin[i] - 1 - leftMin[i]) * heights[i]);
        }
        return mx;


    }
};
