class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()){
            return "";
        }
        // int minLength=INT_MAX;
        // int startingIndex=-1;
        // int count=0;
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
        int freq[256] = {0};
        for (char c : t) freq[c]++;

        int l = 0, r = 0;
        int minLength = INT_MAX, start = -1;
        int need = t.size();

        while (r < s.size()) {
            // Decrease freq, if it's a useful char, reduce need
            if (freq[s[r]] > 0) {
                need--;
            }
            freq[s[r]]--;
            r++;

            // When all needed characters are found
            while (need == 0) {
                if (r - l < minLength) {
                    minLength = r - l;
                    start = l;
                }

                // We're about to remove s[l], so undo its effect
                freq[s[l]]++;
                if (freq[s[l]] > 0) {
                    need++;
                }
                l++;
            }
        }

        return (start == -1) ? "" : s.substr(start, minLength);
    }
};
