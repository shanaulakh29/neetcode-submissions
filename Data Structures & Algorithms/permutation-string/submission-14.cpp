class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
    return false;
}
        int window = s1.size();
        int s1Freq[26]={0};
        int s2Freq[26]={0};
        for(int i=0;i<s1.size();i++){
            s1Freq[s1[i]-'a']+=1;
            s2Freq[s2[i]-'a']+=1;
        }
        int matches=0;
        for(int i=0;i<26;i++){
            if(s1Freq[i]==s2Freq[i]){
                matches+=1;
            }
        }
        int left=0;
        int right=window;
        while(right<s2.size()){
            if(matches==26){
                return true;
            }
            int newIndex = s2[right]-'a';
            s2Freq[newIndex]+=1;
            if(s2Freq[newIndex]==s1Freq[newIndex]){
                matches+=1;
            }else if(s2Freq[newIndex]==s1Freq[newIndex]+1){
                matches-=1;
            }
            right+=1;
            int lostIndex = s2[left]-'a';
            s2Freq[lostIndex]-=1;
            if(s2Freq[lostIndex]==s1Freq[lostIndex]){
                matches+=1;
            }else if(s2Freq[lostIndex]==s1Freq[lostIndex]-1){
                matches-=1;
            }
            left+=1; 
        }
        if(matches==26){
            return true;
        }
        return false;
    }
};
