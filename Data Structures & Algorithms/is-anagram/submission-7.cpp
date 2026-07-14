class Solution {
public:
    bool isAnagram(string s, string t) {
        int array[26]={0};
        if(s.size()!=t.size()){
            return false;
        }
        for(int i=0;i<s.size();i++){
            array[s[i]-'a']+=1;
            array[t[i]-'a']-=1;
        }
        for(int i=0;i<26;i++){
            if(array[i]!=0){
                return false;
            }
        }
        return true;
    }
};
