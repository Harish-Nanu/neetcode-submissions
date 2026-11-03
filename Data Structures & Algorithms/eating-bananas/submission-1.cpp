class Solution {
public:
#define lli long long
    bool check(vector <int>& a, lli mid, lli h){
        lli hours = 0;
        for(lli i = 0; i < a.size(); i++){
            hours += (a[i] + mid - 1) / mid;
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        lli sum = 0, n = piles.size();
        for(lli i = 0; i < n; i++){
            sum += piles[i];
        }
        lli l = 0, r = sum + 1, mid;
        while(l + 1 < r){
            mid = l + (r - l) / 2;
            if(check(piles, mid, h)){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        return r;
    }
};
