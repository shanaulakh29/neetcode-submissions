class Solution {
public:
    void reverse(vector<int>&nums, int left, int right){
        while(left<right){
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left+=1;
            right-=1;
        }
    }
    void rotate(vector<int>& nums, int k) {
        if(k>=nums.size()){
            k = k%nums.size();
        }
        int left=0;
        int right=nums.size()-1;
        reverse(nums, left, right);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);    
    }
};
//[1,2,3,4,5]
//[5,4,3,2,1]
//[]
// 0,1,2,3,4

