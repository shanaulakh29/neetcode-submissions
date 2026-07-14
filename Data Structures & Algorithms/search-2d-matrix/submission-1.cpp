class Solution {
public:
    int getRow(vector<vector<int>>& matrix,int target){//This takes log m time
        int rowl=0;
        int rowr=matrix.size()-1;
        while(rowl<=rowr){
            int mid = rowl+(rowr-rowl)/2;
            if(matrix[mid][0]<=target && matrix[mid][matrix[0].size()-1]>=target){
                return mid;
            }
            else if(matrix[mid][0]<target){
                rowl=mid+1;
            }else if(matrix[mid][0]>target){
                rowr=mid-1;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = getRow(matrix,target);
        if(row==-1){
            return false;
        }
        int l=0;//this takes log n time
        int r=matrix[0].size();
        while(l<=r){
            int mid = l+(r-l)/2;
            if(matrix[row][mid]<target){
                l=mid+1;
            }else if(matrix[row][mid]>target){
                r=mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
};// so in total log m + log n = log(mn) time complexity. Space is O(1)
