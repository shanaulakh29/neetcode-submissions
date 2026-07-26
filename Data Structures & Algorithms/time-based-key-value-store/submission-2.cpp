class TimeMap {
    unordered_map<string,vector<pair<int, string>>>map;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>&v = map[key];
        string value = "";
        int left=0;
        int right=v.size()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(v[mid].first<timestamp){
                value = v[mid].second;
                left=mid+1;
            }else if(v[mid].first>timestamp){
                right=mid-1;
            }else{
                value = v[mid].second;
                break;
            }
        }
        return value;
    }
};
