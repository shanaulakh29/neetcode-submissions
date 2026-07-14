class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int n=s.size();
        // int maxLength=0;
        
        // for(int i=0;i<n;i++){//O(n^2) time and space =O(1)
        //     unordered_map<char,int>mp;
        //     int len=0;
        //     for(int j=i;j<n;j++){
        //         if(mp.find(s[j])==mp.end()){
        //             mp[s[j]]=1;
        //             len++;
        //             maxLength = max(len, maxLength);
        //         }else{
        //             break;
        //         }
        //     }
        // }
        // return maxLength;

        int l=0;
        int r=0;
        int maxLength=0;
        unordered_map<char,int>mp;
        while(r<s.size()){
            if(mp.find(s[r])==mp.end()){
                mp[s[r]]=r;
            }else if(mp[s[r]]>=l){
                l=mp[s[r]]+1;
                mp[s[r]]=r;
            }else{
               mp[s[r]]=r; 
            }
            maxLength = max(maxLength,r-l+1);
            r++;
        }
        return maxLength;
    }
};
