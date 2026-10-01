class Solution {
    vector<vector<int>>dirs={{0,1},{0,-1},{-1,0},{1,0}};
public:
    bool isValid(int row, int col, int maxRows, int maxCols){
        return row>=0 && col>=0 && row<maxRows && col <maxCols;
    }
    void dfs(vector<vector<int>>& heights, int row, int col, set<pair<int,int>>&visited, int prevValue){
        if(!isValid(row, col, heights.size(), heights[0].size()) || heights[row][col]<prevValue || visited.contains({row, col})){
            return;
        }
        visited.insert({row, col});
        for(vector<int>dir: dirs){
            int newRow = row+dir[0];
            int newCol = col+dir[1];
            dfs(heights, newRow, newCol, visited, heights[row][col]);
            
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        set<pair<int,int>>pacific;
        set<pair<int,int>>atlantic;
        int rows = heights.size();
        int cols = heights[0].size();
        for(int c=0;c<cols;c++){
            dfs(heights, 0, c, pacific, heights[0][c]);
            dfs(heights, rows-1,c, atlantic, heights[rows-1][c]);
        }
        for(int r=0;r<rows;r++){
            dfs(heights, r, 0, pacific, heights[r][0]);
            dfs(heights, r,cols-1, atlantic, heights[r][cols-1]);
        }
        vector<vector<int>>res;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(pacific.contains({r,c}) && atlantic.contains({r,c})){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    
    }
};
