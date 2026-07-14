class Solution {
public:
    void dfs(int v, unordered_map<int, vector<int>>&mp,unordered_set<int>&set){
        if(set.find(v)!=set.end()){
            return;
        }
        set.insert(v);
        vector<int>edges = mp[v];
        for(int i=0;i<edges.size();i++){
            dfs(edges[i],mp,set);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>mp;
        for(auto edge: edges){
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        int count=0;
        unordered_set<int>set;
        for(int i=0;i<n;i++){
            if(set.find(i)==set.end()){
                count++;
                dfs(i,mp,set);
            }
        }
        return count;
    }
};
