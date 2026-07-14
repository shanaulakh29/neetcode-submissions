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
            //if s[r]is not in the hash yet then add it
            if(mp.find(s[r])==mp.end()){
                mp[s[r]]=r;
            }
            //if value s[r] is already in mp[s[r]] and mp[s[r]]>=l then this means the repeated value at position r is comming between the l and r. 
            //so increment l to one next to the index already stored index of s[r]
            //this allows us to calculate exact diff between l and r .Since we already had the maxLength before the repeated value occured, and when the value repeats, we increment l to one next of the previous location of s[r] and we start getting the new length by doing r-l+1
            else if(mp[s[r]]>=l){
                l=mp[s[r]]+1;
                mp[s[r]]=r;
            }
            //
            else{
               mp[s[r]]=r; 
            }
            maxLength = max(maxLength,r-l+1);
            r++;
        }
        return maxLength;
    }
};
