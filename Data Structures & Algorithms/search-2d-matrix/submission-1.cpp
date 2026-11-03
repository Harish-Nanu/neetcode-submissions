class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int ind = -1, r = n, mid;
        while(ind + 1 < r){
            mid = ind + (r - ind) / 2;
            if(matrix[mid][0] < target){
                ind = mid;
            }
            else if (matrix[mid][0] > target){
                r = mid;
            }
            else{
                return true;
            }
        } 
        if(ind < 0){
            return false;
        }
        int l = -1; r = m;
        while(l + 1 < r){
            mid = l + (r - l) / 2;
            if(matrix[ind][mid] < target){
                l = mid;
            }
            else if(matrix[ind][mid] > target){
                r = mid;
            }
            else{
                return true;
            }
        }
        return false;

    }
};
