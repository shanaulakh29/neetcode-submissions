class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>>row;
        unordered_map<int, unordered_set<char>> col;
        unordered_map<string, unordered_set<char>>grid;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(!row[i].contains(board[i][j]) && 
                !col[j].contains(board[i][j]) &&
                !grid[to_string(i/3)+to_string(j/3)].contains(board[i][j])){
                    if(board[i][j]=='.'){
                        continue;
                    }
                    char val = board[i][j];
                    row[i].insert(val);
                    col[j].insert(val);
                    grid[to_string(i/3)+to_string(j/3)].insert(val);
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
