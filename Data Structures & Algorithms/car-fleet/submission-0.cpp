class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector <int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int x, int y){
            return position[x] < position[y];
        });
        stack <float> st;
        for(int i = 0; i < n; i++){
            float time = ((float)target - (float)position[idx[i]]) / (float)speed[idx[i]];
            if(!st.empty()){
                while(!st.empty() && st.top() <= time){
                    st.pop();
                }
            }
            st.push(time);
            // cout << st.top() << endl;
        }
        int cnt = 0;
        while(!st.empty()){
            cnt++;
            st.pop();
        }
        return cnt;
    }
};
