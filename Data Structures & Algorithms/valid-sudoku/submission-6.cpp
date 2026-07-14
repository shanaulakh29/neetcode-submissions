class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>row[9],col[9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                string val(1, board[i][j]);
                if(val=="."){
                    continue;
                }
                if(row[i].count(val)||col[j].count(val)){
                    return false;
                }else{
                    row[i].insert(val);
                    col[j].insert(val);
                }
            }
        }
        unordered_map<string,unordered_set<string>>box;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                string val(1, board[i][j]);
                if(val=="."){
                    continue;
                }
                string boxi=to_string(i/3);
                string boxj=to_string(j/3);
                string key = boxi+boxj;
                if(box[key].find(val)!=box[key].end()){
                    return false;
                }else{
                box[key].insert(val);
                }
            }
        }
        return true;
    }
};
