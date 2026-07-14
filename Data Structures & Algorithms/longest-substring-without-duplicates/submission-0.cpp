class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxLength=0;
        
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            int len=0;
            for(int j=i;j<n;j++){
                if(mp.find(s[j])==mp.end()){
                    mp[s[j]]=1;
                    len++;
                    maxLength = max(len, maxLength);
                }else{
                    break;
                }
            }
        }
        return maxLength;
    }
};
