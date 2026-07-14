class Solution {
public:
    int findMin(vector<int> &nums) {
        int left=0;
        int right=nums.size()-1;
        int res=nums[left];
        while(left<=right){
          if(nums[left]<=nums[right]){
            res = min(res, nums[left]);
            break;
          }
          int mid = (left+right)/2;
          res = min(nums[mid],res);
          if(nums[mid]>=nums[left]){
            left=mid+1;
          }else{
            right=mid-1;
          }
        }
        return res;
    }
};
