class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
          unordered_set<string>s;
        for(int row=0;row<board.size();row++){ // O(n^2)
            for(int col=0;col<board.size();col++){
                char val = board[row][col];
                if(val=='.') continue;
                string strVal(1,val);
                if(!s.insert("value at row "+to_string(row)+"is "+strVal).second ||
                !s.insert("value at col "+to_string(col)+"is "+strVal).second ||
                !s.insert("value at box "+to_string(row/3)+","+to_string(col/3)+"is "+strVal).second){
                    return false;
                }
            }
        }
        return true;
    }
};
