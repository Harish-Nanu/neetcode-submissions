class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int mid, mxd;
        int mx = 0;
        vector <int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int x, int y){
            return heights[x] > heights[y];
        });
        mid = mxd = idx[0];
        for(int i = 1; i < n; i++){
            int dist = max(abs(idx[i] - mid), abs(idx[i] - mxd));
            mx = max(mx, heights[idx[i]] * dist);
            mxd = max(mxd, idx[i]);
            mid = min(mid, idx[i]);
        }
        return mx;
    }
};
