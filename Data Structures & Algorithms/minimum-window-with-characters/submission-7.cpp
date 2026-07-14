class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()){
            return "";
        }
        int minLength=INT_MAX;
        int startingIndex=-1;
        int count=0;
        // for(int i=0;i<s.size();i++){//O(n^2) since for each char in s as the starting character, we go through the remaining chars to find the matching substrings and then update the minlength and startingIndex
        //     count=0;
        //     int freq[256]={0};
        //     for(int k=0;k<t.size();k++){
        //         freq[t[k]]+=1;
        //     }
        //     for(int j=i;j<s.size();j++){
        //         if(freq[s[j]]>0){
        //             count++;
        //         }
        //         freq[s[j]]--;
        //         if(count==t.size()){
        //             minLength = min(minLength, j-i+1);
        //             startingIndex = i;
        //         }
        //     }
        // }
        // return s.substr(startingIndex,minLength);
        int freq[256]={0};
        for(char c: t){
            freq[c]+=1;
        }
        int l=0;
        int r=0;
        while(r<s.size()){
            if(freq[s[r]]>0){
                count++;
            }
            freq[s[r]]--;
            while(count == t.size()){
                if(r-l+1<minLength){
                    minLength = r-l+1;
                    startingIndex=l;
                }
                freq[s[l]]+=1;
                if(freq[s[l]]>0){
                    count=count-1;
                }
                l++;
            }
            r++;
        }
        if(startingIndex==-1){
            return "";
        }
        return s.substr(startingIndex, minLength);
    }
};
