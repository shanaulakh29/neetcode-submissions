class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>mp;
        for(string s: strs){
            string dups = s;
            std::sort(dups.begin(),dups.end());
            mp[dups].push_back(s);
        }
        for(auto pair : mp){
            res.push_back(pair.second);
        }
        return res;
    }
};
