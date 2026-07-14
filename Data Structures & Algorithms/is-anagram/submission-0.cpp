class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        int array[256]={0};
        for(int i=0;i<s.length();i++){
            array[s[i]]+=1;
            array[t[i]]-=1;
        }
        for(int i=0;i<256;i++){
            if(array[i]!=0){
                return false;
            }
        }
        return true;
    }
};
