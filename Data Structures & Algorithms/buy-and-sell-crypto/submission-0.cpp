class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = 0, n = prices.size();
        int tmp = 0;
        for(int i = 1; i < n; i++){
            int diff = prices[i] - prices[i-1];
            if(tmp + diff > 0){
                tmp += diff;
            }
            else{
                tmp = 0;
            }
            mx = max(mx, tmp);
        }
        return mx;
    }
};
