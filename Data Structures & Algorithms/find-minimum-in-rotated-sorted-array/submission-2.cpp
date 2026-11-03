class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n-1, mid;
        while(l + 1 < r){
            mid = l + (r - l) / 2;
            int left = nums[l], right = nums[r], m = nums[mid];
            if(left < m && m < right){
                r = mid;
            }
            else if(left > m && m < right){
                r = mid;
            }
            else if(left < m == m > right){
                l = mid;
            }
            else{   
                l = mid;
            }
        }
        vector <int> temp = {nums[0], nums[n-1], nums[l], nums[r]};
        return *min_element(temp.begin(), temp.end());
    }
};
