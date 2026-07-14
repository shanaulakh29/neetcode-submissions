class Solution {
public:
    bool isSame(const string &s1, string &s2){
        if(s1.size()!=s2.size()){
            return false;
        }
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                return false;
            }
        }
        return true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int sSize = s.size();
        vector<bool>dp(sSize+1, false);
        dp[sSize]=true;
        for(int i=sSize-1;i>=0;i--){
            for(string word:wordDict){
                int wordSize = word.size();
                if(i+wordSize<=sSize && isSame(s.substr(i,wordSize), word)){
                    if(dp[i+wordSize]){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};

