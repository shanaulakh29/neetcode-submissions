class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        int s1_array[26]={0};
        int s2_array[26]={0};
        for(int i=0;i<s1.size();i++){
            s1_array[s1[i]-'a']+=1;
            s2_array[s2[i]-'a']+=1;
        }
        int matches=0;
        for(int i=0;i<26;i++){
            if(s1_array[i]==s2_array[i]){
                matches+=1;
            }
        }
        int left=0;
        int right=s1.size();
        while(right<s2.size()){
            if(matches==26){
                return true;
            }
            int rIndex = s2[right]-'a';
            s2_array[rIndex]+=1;
            if(s1_array[rIndex ] == s2_array[rIndex ]){
                matches+=1;
            }else if(s2_array[rIndex] == s1_array[rIndex]+1){
                matches-=1;
            }

            s2_array[s2[left]-'a']-=1;
            if(s1_array[s2[left]-'a'] == s2_array[s2[left]-'a']){
                matches+=1;
            }else if(s2_array[s2[left]-'a'] == s1_array[s2[left]-'a']-1){
                matches-=1;
            }
            left++;
            right++;
        }
        if(matches==26){
            return true;
        }
        return false;
    }
};
