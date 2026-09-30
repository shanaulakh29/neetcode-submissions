class Solution {
public:
    int findRow(vector<vector<int>>&matrix, int target){
        int left=0;
        int right = matrix.size()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(matrix[mid][0]>target){
                right=mid-1;
            }else if(matrix[mid][matrix[0].size()-1]<target){
                left=mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = findRow(matrix, target);
        if(row==-1){
            return false;
        }
        int left=0;
        int right = matrix[0].size()-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(matrix[row][mid]==target){
                return true;
            }else if(matrix[row][mid]>target){
                right=mid-1;
            }else {
                left=mid+1;
            }
        }
        return false;
    }
};
