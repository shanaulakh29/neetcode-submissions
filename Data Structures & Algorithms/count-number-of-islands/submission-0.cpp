class Solution {
public:
    bool inBounds(int row, int col,vector<vector<char>>& grid){
        return row>=0 && row<grid.size() && col>=0 && col<grid[0].size();
    }
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>&visited, int r,int c){
        visited[r][c]=true;
        queue<pair<int,int>>q;
        q.push({r,c});
        vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();
            for(auto dir: directions){
                int row = p.first+dir[0];
                int col = p.second+dir[1];
                if(inBounds(row,col,grid)&& !visited[row][col] && grid[row][col]=='1'){
                    visited[row][col]=true;
                    q.push({row,col});
                }
            }  
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands =0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    islands++;
                    bfs(grid, visited,i,j);
                }
            }
        }
        return islands;
    }
};
