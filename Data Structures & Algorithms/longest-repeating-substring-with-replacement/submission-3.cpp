class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxFrequency = 0;
        int windowSize=0;
        int freq[26]={0};
        while(r<s.size()){
            freq[s[r]-'A']+=1;
            maxFrequency = max(maxFrequency, freq[s[r]-'A']);
            windowSize = r-l+1;
            if(windowSize-maxFrequency>k){
                freq[s[l]-'A']-=1;
                l++;
                windowSize = r-l+1;
            }
            r++;
        }
        return windowSize;
    }
};