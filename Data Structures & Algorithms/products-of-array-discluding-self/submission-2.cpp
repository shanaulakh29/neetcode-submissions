class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
//nums = [1,2,4,6]
//left = [1,1,2,8]

//nums = [1,2,4,6]
//right =[48,24,6,1]
        vector<int>left(nums.size());
        vector<int>right(nums.size());
        left[0]=1;
        for(int i=1;i<nums.size();i++){
            left[i] = nums[i-1]*left[i-1];
        }
        right[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;i--){
            right[i] = nums[i+1]*right[i+1];
        }
        vector<int>output(nums.size());
        for(int i=0;i<nums.size();i++){
            output[i] = left[i]*right[i];
        }
        return output;
    }
};
