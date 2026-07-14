class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>s;
        for(int row=0;row<board.size();row++){
            for(int col=0;col<board[0].size();col++){
                char val = board[row][col];
                if(val=='.'){
                    continue;
                }
                string valStr(1,val);
                if(!s.insert("value at row "+to_string(row)+"is "+valStr).second ||
                !s.insert("value at col "+to_string(col)+" is"+ valStr).second||
                !s.insert("value of box at row["+to_string(row/3)+","+to_string(col/3)+"] is "+valStr).second){
                    return false;
                }
            }
        }
        return true;
    }
};
