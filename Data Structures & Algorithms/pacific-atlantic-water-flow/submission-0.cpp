class Solution {
public:
    bool inBound(int row, int col, vector<vector<int>>& heights){
        return row>=0 && row<heights.size()&& col>=0 && col<heights[0].size();
    }
    void dfs(int row, int col, vector<vector<bool>>&vis,vector<vector<int>>& heights){
        vis[row][col]=true;
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(vector<int>d:dir){
            int newr = row+d[0];
            int newc = col+d[1];
            if(inBound(newr,newc,heights) && !vis[newr][newc] && heights[newr][newc] >= heights[row][col]){
                dfs(newr,newc,vis,heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>>res;
        vector<vector<bool>>pac(rows,vector<bool>(cols, false));
        vector<vector<bool>>atl(rows,vector<bool>(cols, false));
        for(int c=0;c<cols;c++){
            dfs(0,c,pac,heights);
            dfs(rows-1,c,atl,heights);
        }
        for(int r=0;r<rows;r++){
            dfs(r,0,pac,heights);
            dfs(r,cols-1,atl,heights);
        }
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(pac[r][c]&& atl[r][c]){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
};
