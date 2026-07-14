class Solution {
    vector<vector<string>>res;
public:
    bool isPalindrome(string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void dfs(string &s,int index,vector<string>&partitions){
        if(index>=s.size()){
            res.push_back(partitions);
            return;
        }
        for(int j=index;j<s.size();j++){
           if(isPalindrome(s,index,j)){
            partitions.push_back(s.substr(index, j - index + 1));
            dfs( s, j+1,partitions);
            partitions.pop_back();
           } 
        }  
    }
    vector<vector<string>> partition(string s) {
        vector<string>partitions;
        dfs(s,0, partitions);
        return res;
    }
};
