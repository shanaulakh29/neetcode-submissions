class Solution {
public:
    int getRow(vector<vector<int>>& matrix, int target){
        int top=0;
        int bottom=matrix.size()-1;
        while(top<=bottom){
            int mid = top+(bottom-top)/2;
            if(matrix[mid][0]<=target && target<= matrix[mid][matrix[0].size()-1]){
                return mid;
            }else if(matrix[mid][0]<target){
                top=mid+1;
            }else{
                bottom=mid-1;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = getRow(matrix, target);
        if(row==-1){
            return false;
        }
        int left=0;
        int right=matrix[0].size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(target>matrix[row][mid]){
                left=mid+1;
            }else if(target<matrix[row][mid]){
                right=mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
};
