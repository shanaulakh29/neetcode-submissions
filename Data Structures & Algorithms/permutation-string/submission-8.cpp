class Solution {
public:
    bool checkMatch(unordered_map<char, int>&s1_map,unordered_map<char, int>&s2_map){
        for(auto & pair:s1_map){
            char c = pair.first;
            int count = pair.second;
            if(s2_map[c]!=count){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        unordered_map<char, int>s1_map;
        unordered_map<char, int>s2_map;
        for(int i=0;i<s1.size();i++){
            s1_map[s1[i]]+=1;
            s2_map[s2[i]]+=1;
        }
        int left=0;
        int right=s1.size();
        while(right<s2.size()){
            if(checkMatch(s1_map, s2_map)){
                return true;
            }
            s2_map[s2[right]]+=1;
            s2_map[s2[left]]-=1;
            right+=1;
            left+=1;
        }
        if(checkMatch(s1_map, s2_map)){
            return true;
        }
        return false;
    }
};
