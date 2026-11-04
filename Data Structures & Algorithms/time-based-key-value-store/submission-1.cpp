class TimeMap {
public:
    unordered_map <string, vector <pair <int, string>>> mp;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        int n = mp[key].size();
        int l = -1, r = n, mid;
        if(n == 0){
            return "";
        }
        while(l + 1 < r){
            mid = l + (r - l) / 2;
            if(mp[key][mid].first <= timestamp){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        if(l < 0){
            return "";
        }
        return mp[key][l].second;
    }
};
