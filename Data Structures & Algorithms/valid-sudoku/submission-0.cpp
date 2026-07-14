class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<board.size();row++){
            unordered_set<char>set;
            for(int col=0;col<board[0].size();col++){
                char val = board[row][col];
                 if ( val == '.'){
                    continue;
                }
                else if(set.find(val)==set.end()){
                    set.insert(val);
                }else{
                    return false;
                }
            }
        }
        for(int col=0;col<board[0].size();col++){
            unordered_set<char>set;
            for(int row=0;row<board.size();row++){
                char val = board[row][col];
                 if ( val == '.'){
                    continue;
                }
                else if(set.find(val)==set.end()){
                    set.insert(val);
                }else{
                    return false;
                }
            }
        }
        for(int row=0;row<9;row+=3){ 
            for(int col=0;col<9;col+=3){
                unordered_set<char>set;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        char val = board[row+i][col+j];
                        if ( val == '.'){
                            continue;
                        }
                        else if(set.find(val)==set.end()){
                            set.insert(val);
                        }else{
                            return false;
                        }
                    }
                }
               
            }
        }
        return true;
    }
};
