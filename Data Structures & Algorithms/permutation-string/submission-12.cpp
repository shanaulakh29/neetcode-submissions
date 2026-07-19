class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        int freq1[26]={0};
        for(int i=0;i<s1.size();i++){
            freq1[s1[i]-'a']+=1;
        }
        for(int i=0;i<=s2.size()-s1.size();i++){
            bool match=true;
            int freq2[26]={0};
            for(int j=0;j<s1.size();j++){
                freq2[s2[i+j]-'a']+=1;
            }
            for(int k=0;k<26;k++){
                if(freq1[k]!=freq2[k]){
                    match=false;
                    break;
                }
            }
            if(match){
                return true;
            }
        }
        return false;

    }
};
//             012         0123
//Input: s1 = "abc", s2 = "leca"