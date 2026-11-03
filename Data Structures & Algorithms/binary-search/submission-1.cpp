class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1, r = n, mid;
        while(l + 1 < r){
            mid = l + (r-l) / 2;
            if(nums[mid] > target){
                r = mid;
            }
            else if (nums[mid] < target){
                l = mid;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};
