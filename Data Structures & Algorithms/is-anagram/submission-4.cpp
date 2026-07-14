class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.size()!=t.size()){
        return false;
      }  
      map<char,int>mp1;
      for(int i=0;i<s.size();i++){
        mp1[s[i]]+=1;
        mp1[t[i]]-=1;
      }
      for(int i=0;i<t.size();i++){
        if(mp1[s[i]]){
            return false;
        }
      }
        return true;
    }
};
