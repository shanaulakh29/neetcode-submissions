class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>map;
        for(string str:strs){
            string dup=str;
            std::sort(dup.begin(),dup.end());
            map[dup].push_back(str);
        }
        vector<vector<string>>res;
        for(pair p:map){
            res.push_back(p.second);
        }
        return res;
    }
};
