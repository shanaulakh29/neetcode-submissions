class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int midIndex = left+(right-left/2);
            if(nums[midIndex]>target){
                right=midIndex-1;
            }else if(nums[midIndex]<target){
                left=midIndex+1;
            }else{
                return midIndex;
            }
        }
        return -1;
    }
};
