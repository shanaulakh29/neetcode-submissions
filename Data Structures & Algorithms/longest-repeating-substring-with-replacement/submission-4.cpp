class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>freq;
        int left=0;
        int maxFrequency=0;
        int windowSize=0;
        for(int right=0;right<s.size();right++){
            freq[s[right]]+=1;
            maxFrequency = max(maxFrequency,freq[s[right]]);
            windowSize=right-left+1;
            while(windowSize - maxFrequency >k){
                freq[s[left]]-=1;
                left+=1;
                windowSize=right-left+1;
            }
        }
        return windowSize;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // int l=0;
        // int r=0;
        // int maxFrequency = 0;
        // int windowSize=0;
        // int freq[26]={0};
        // while(r<s.size()){
        //     freq[s[r]-'A']+=1;
        //     maxFrequency = max(maxFrequency, freq[s[r]-'A']);
        //     windowSize = r-l+1;
        //     if(windowSize-maxFrequency>k){
        //         freq[s[l]-'A']-=1;
        //         l++;
        //         windowSize = r-l+1;
        //     }
        //     r++;
        // }
        // return windowSize;
    }
};