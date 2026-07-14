class Solution {
    // unordered_set<pair<int,int>>set;  
public:
    bool dfs(vector<vector<char>>& board,string &word,vector<vector<bool>>&visited, int r,int c, int wordIndex){
        if(wordIndex==word.size()){
            return true;
        }
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c]!=word[wordIndex] || visited[r][c]){
            return false;
        }
        visited[r][c]=true;
        bool res = (dfs(board,word,visited,r+1,c,wordIndex+1)||
        dfs(board,word,visited,r-1,c,wordIndex+1) ||
        dfs(board,word,visited,r,c+1,wordIndex+1) ||
        dfs(board,word,visited,r,c-1,wordIndex+1));
        visited[r][c] = false;
        return res;

    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(dfs(board,word,visited,r,c,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
