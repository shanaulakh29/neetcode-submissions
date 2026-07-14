class TimeMap {
private:
    unordered_map<string, vector<pair<string,int>>> mp; 
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& array = mp[key];
        if(array.size()==0){
            return "";
        }
        int l=0;
        int r = array.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            pair<string,int> p=array[mid];
            if(p.second<timestamp){
                l=mid+1;
            }else if(p.second>timestamp){
                r=mid-1;
            }else{
                return p.first;
            }
        }
        if(r==-1){
            return "";
        }
        pair<string,int> p=array[r];
        return p.first;   
    }
};
