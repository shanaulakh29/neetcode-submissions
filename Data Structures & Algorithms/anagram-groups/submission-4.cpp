class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>map;
        for(string str:strs){
           vector<int>freq(26,0);
           for(char c:str){
            freq[c-'a']+=1;
           }
           string key="";
           for(int i=0;i<26;i++){
            key+=to_string(freq[i])+"#";
           }
           map[key].push_back(str);
        }
        vector<vector<string>>res;
        for(pair<string, vector<string>> p:map){
            res.push_back(p.second);
        }
        return res;
    }
};
