class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>map;
        for(string str:strs){
            int array[26]={0};
            for(char c:str){
                array[c-'a']+=1;
            }
            string key="";
            for(int i=0;i<26;i++){
                key+=to_string(array[i])+"#";
            }
            map[key].push_back(str);
        }
        vector<vector<string>>res;
        for(auto &pair:map){
            res.push_back(pair.second);
        }
        return res;
    }
};
//str1 = "ab" 1#1
//str2 = "aaaaaaaaaaa" 11#