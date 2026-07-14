class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int currMin=nums[0];
        int currMax=nums[0];
        for(int i=1;i<nums.size();i++){
            int num=nums[i];
            int temp = num*currMax;
            currMax = max({num*currMax, num*currMin, num});
            currMin = min({temp, num*currMin, num});
            res = max(res, currMax);
        }
        return res;
    }
};
