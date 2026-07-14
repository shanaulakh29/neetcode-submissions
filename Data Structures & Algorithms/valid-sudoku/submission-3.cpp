class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<board.size();row++){
            unordered_set<char>s;
            for(int col=0;col<board.size();col++){
                if(board[row][col]=='.'){
                    continue;
                }
                else if(!s.insert(board[row][col]).second){
                    return false;
                }
            }
        }
        for(int col=0;col<board.size();col++){
            unordered_set<char>s;
            for(int row=0;row<board.size();row++){
                if(board[row][col]=='.'){
                    continue;
                }
                if(!s.insert(board[row][col]).second){
                    return false;
                }
            }
        }
        for(int row=0;row<board.size();row+=3){
            for(int col=0;col<board.size();col+=3){
                unordered_set<char>s;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        char val = board[i+row][j+col];
                        if(val=='.'){
                            continue;
                        }
                        else if(!s.insert(val).second){
                            return false;
                        }
                    }
                }
                
            }
        }
        return true;    
    }
};
