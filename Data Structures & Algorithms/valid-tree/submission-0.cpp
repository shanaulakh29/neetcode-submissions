class Solution {
public:
    bool dfs(int v, unordered_set<int>&set,unordered_map<int, vector<int>>&mp, int parent){
        if(set.find(v)!=set.end()){
            return false;
        }
        set.insert(v);
        for(auto edge:mp[v]){
            if(edge!=parent){
                if(!dfs(edge, set,mp, v)){
                    return false;
                }
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>mp;
        for(auto edge:edges){
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        unordered_set<int>set;
        if(!dfs(0,set,mp,-1)){
            return false;
        }
        if(set.size()!=n){
            return false;
        }
        return true;
    }
};
