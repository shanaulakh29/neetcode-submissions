class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;
        unordered_map<char,int>map;
        int maxFrequency=0;
        int window=0;
        int maxLength=0;
        while(right<s.size()){
            map[s[right]]+=1;
            maxFrequency = max(maxFrequency, map[s[right]]);
            window = right-left+1;
            if(window-maxFrequency>k){
                map[s[left]]-=1;
                left+=1;
                window = right-left+1;
            }
            maxLength = max(maxLength,window);
            right+=1;
        }
        return maxLength;
    }
};
