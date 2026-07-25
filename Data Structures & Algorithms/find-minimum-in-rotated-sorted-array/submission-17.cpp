class Solution {
public:
    int findMin(vector<int> &nums) {
        //[1,2,3,4,5,6]
        //[6,1,2,3,4,5] 1
        //[5,6,1,2,3,4] 2
        //[4,5,6,1,2,3] 3
        //[3,4,5,6,1,2] 4
        //[2,3,4,5,6,1] 5

        int left=0;
        int right=nums.size()-1;
        int minValue = INT_MAX;
        while(left<=right){
            if(nums[left]<=nums[right]){
                minValue = min(minValue, nums[left]);
                return minValue;
            }
            int mid = left+((right-left)/2);
            minValue = min(minValue, nums[mid]);
            if(nums[mid]>=nums[left]){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return minValue;
    }
};
