class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS=matrix.size();
        int COLS=matrix[0].size();
        int top=0;
        int bot=ROWS-1;
        while(top<=bot){
            int mid = (top+bot)/2;
            if(matrix[mid][COLS-1]<target){
                top=mid+1;
            }else if(matrix[mid][0]>target){
                bot=mid-1;
            }else{
                break;
            }
        }
        if(!(top<=bot)){
            return false;
        }
        int midRow = (top+bot)/2;
        int left=0;
        int right=COLS-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(matrix[midRow][mid]<target){
                left=mid+1;
            }else if(matrix[midRow][mid]>target){
                right=mid-1;
            }else{
                return true;
            }
        }
        return false;   
    }
};
