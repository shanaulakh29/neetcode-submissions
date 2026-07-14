class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        int l=0;
        int r=0;
        int freq[26]={0};
        for(char c: s1){
            freq[c-'a']++;
        }
        int windowSize=s1.size();
        while(r<s2.size()){
            if(freq[s2[r]-'a']>0){
                windowSize--; //I found one of the char in substring so i need windowSize-1 characters more
            }
            freq[s2[r]-'a']--;
            if(windowSize==0){
                return true;
            }
            if(r-l+1==s1.size()){//since windowSize!=0, this means for next iteration, r is moving beyond the windowSize and to counter that we want to move l forward. 
            //also since we are moving l forward we want to check if char at l is part of substring. if yes then we need to increase the windowsize since that char and other 2 chars are not making up the correct permutation we need.
                if(freq[s2[l]-'a']>=0){
                    windowSize++;//since 
                }
                freq[s2[l]-'a']++;
                l++;
            }
            r++;
        }
        return false;

    }
};
