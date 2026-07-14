class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.size()!=t.size()){
      return false;
    }
    map<int,int>m;
    for(int i=0;i<s.size();i++){
        m[s[i]]+=1;
    }
    for(int i=0;i<t.size();i++){
        m[t[i]]-=1;
    }
    for(int i=0;i<s.size();i++){
        if(m[s[i]]){
            return false;
        }
    }
    return true;
    }
};
