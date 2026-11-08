class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>res(nums.size());
        for(int i=0;i<nums.size();i++){
            int targetIndex = i+k;
            if(i+k>nums.size()-1){
                targetIndex = targetIndex % nums.size();
            }
                res[targetIndex]=nums[i];
        }
        nums = res;
    }
};
//[1,2,3,4,5]
// 0,1,2,3,4