class Solution {
public:
//[2,1,5,1,5,3]
//     L 
//           R
//L = 5
//sum = 14 
    int minSubArrayLen(int target, vector<int>& nums) {
        int runningTotal = 0;
        int left=0;
        int right=0;
        int minLength = INT_MAX;
        while(right<nums.size()){
            runningTotal+=nums[right];
            right+=1;
            if(runningTotal<target){  
                continue;
            }
            minLength = min(minLength, right-left);

            while(target<=runningTotal-nums[left]){
                runningTotal-=nums[left];
                left+=1;
                minLength = min(minLength, right-left);
            }
        }
        if(minLength==INT_MAX){
            return 0;
        }
        return minLength;
    }
};