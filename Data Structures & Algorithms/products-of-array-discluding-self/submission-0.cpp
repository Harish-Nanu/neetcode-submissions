class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prod = 1, zr = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]){
                prod *= nums[i];
            }
            else{
                zr++;
            }
        }
        vector <int> ans(n);
        for(int i = 0; i < n; i++){
            if(!nums[i]){
                if(zr > 1){
                    ans[i] = 0;
                }
                else{
                    ans[i] = prod;
                }
            }
            else{
                if(zr > 0){
                    ans[i] = 0;
                }
                else{
                    ans[i] = prod / nums[i];
                }
            }
        }
        return ans;
    }
};
