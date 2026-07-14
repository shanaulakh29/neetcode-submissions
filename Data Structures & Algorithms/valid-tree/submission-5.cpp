class Solution {
public:
    bool dfs(int currNode, int parent,unordered_map<int, vector<int>>&map, unordered_set<int>&visited){
        if(visited.contains(currNode)){
            return false;
        }
        visited.insert(currNode);
        for(int & v:map[currNode]){
            if(v==parent){
                continue;
            }
            if(!dfs(v, currNode, map, visited)){
                return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>map;
        for(auto& edge : edges){
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }
        unordered_set<int>visited;
        if(!dfs(0,-1,map, visited)){
            return false;
        }

        if(visited.size()!=n){
                return false;
        }
        return true;
    }
};
