class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right=0;
        int runningSum=0;
        int minWindow = INT_MAX;
        for(int i=0;i<nums.size();i++){
            runningSum+=nums[i];
            if(runningSum>=target){
                right=i;
                break;
            }
            right+=1;
        }
        while(right<nums.size()){
            while(runningSum-nums[left]>=target){
                runningSum = runningSum-nums[left];
                left+=1;
            }
            minWindow = min(minWindow, right-left+1);
            right+=1;
            if(right<nums.size()){
                runningSum+=nums[right];
            }
        }
        return minWindow==INT_MAX?0:minWindow;
    }
};