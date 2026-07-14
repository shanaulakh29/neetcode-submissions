class Solution {
    vector<vector<string>>res;
public:
    bool isPalindrome(string &s, int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void dfs(string &s, vector<string>&partitions,int i){
        if(i==s.size()){
            res.push_back(partitions);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(isPalindrome(s,i,j)){
                partitions.push_back(s.substr(i,j-i+1));
                dfs(s,partitions,j+1);
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>partitions;
        dfs(s,partitions,0);
        return res;
    }
};
