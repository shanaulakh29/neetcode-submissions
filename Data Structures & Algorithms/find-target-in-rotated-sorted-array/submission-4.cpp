class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(target==nums[mid]){
                return mid;
            }
            //left half
            if(nums[mid]>=nums[left]){
                if(nums[left]>target || nums[mid]<target){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
            //right half
            else{
                if(target>nums[right]|| nums[mid]>target){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }   
        }
        return -1;   
    }
};
//m=6      target=2
//[4,5,6,1,2,3]
//
//[5,6,1,2,3,4]
//m=5
//[3,4,5,6,1,2]
//m=4
//[2,3,4,5,6,1]
//m=3
//[1,2,3,4,5,6]
//m=1


