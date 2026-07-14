class Solution {
public:
    void dfs(int currNode, unordered_map<int, vector<int>>&map,unordered_set<int>&visited){
        if(visited.contains(currNode)){
            return;
        }
        visited.insert(currNode);
        for(int & node: map[currNode]){
            dfs(node, map, visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>map;
        for(auto edge:edges){
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }
        int count=0;
        unordered_set<int>visited;
        for(int i=0;i<n;i++){
            if(!visited.contains(i)){
                dfs(i,map, visited);
                count++;
            }
        }
        return count;
    }
};
