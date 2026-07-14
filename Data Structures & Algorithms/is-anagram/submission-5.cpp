class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.size()!=t.size()){//O(1)
        return false;
      }  
      map<char,int>mp1;
      for(int i=0;i<s.size();i++){//O(n)
        mp1[s[i]]+=1;//O(1)
        mp1[t[i]]-=1;
      }
      for(int i=0;i<t.size();i++){//O(n)
        if(mp1[s[i]]){//O(1)
            return false;
        }
      }
        return true;
    }
};
