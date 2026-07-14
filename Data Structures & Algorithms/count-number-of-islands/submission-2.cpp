class Solution {
public:
    bool inBound(int &newRow, int& newCol, int& maxRows, int& maxCols){
        if(newRow<maxRows && newCol < maxCols && newRow>=0 && newCol>=0){
            return true;
        }
        return false;
    }
    void bfs(vector<vector<char>>& grid, set<pair<int,int>>&visited, int & islands, int &r, int&c){
        int maxRows = grid.size();
        int maxCols = grid[0].size();
        queue<pair<int,int>>q;
        q.push({r,c});
        visited.insert({r,c});
        while(!q.empty()){
            auto pair = q.front();
            q.pop();
            int row = pair.first;
            int col = pair.second;
            vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
            for(auto dir:directions){
                int newRow = dir[0]+row;
                int newCol = dir[1]+col;
                if(inBound(newRow, newCol, maxRows, maxCols) && !visited.contains({newRow, newCol}) && grid[newRow][newCol]=='1'){
                    q.push({newRow, newCol});
                    visited.insert({newRow, newCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {

        int islands=0;
        set<pair<int,int>>visited;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]=='1' && !visited.contains({r,c})){
                    bfs(grid, visited, islands, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }
};
