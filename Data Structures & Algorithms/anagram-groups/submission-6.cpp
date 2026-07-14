class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string, vector<string>>map;

        for(string& str:strs){
            string key="";
            int array[26]={0};
            for(char &c:str){
                array[c-'a']+=1;
            }
            for(int i=0;i<26;i++){
                key+=to_string(array[i])+"#";
            }
            map[key].push_back(str);
        }
        for(auto& p:map){
            res.push_back(p.second);
        }
        return res;
    }
};
