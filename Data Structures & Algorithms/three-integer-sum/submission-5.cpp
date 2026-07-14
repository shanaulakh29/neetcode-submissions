class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        std::sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            int sum= 0-nums[i];
            int low=i+1;
            int high=nums.size()-1;
            while(low<high){
                if(sum==nums[low]+nums[high]){
                    res.push_back(vector<int>{nums[i],nums[low],nums[high]});
                    while(low<high && nums[low]==nums[low+1]){
                        low++;
                    }
                    while(low<high && nums[high]== nums[high-1]){
                        high--;
                    }
                    low++;
                    high--;
                }else if(nums[low]+nums[high] > sum ){
                    high--;
                }else{
                    low++;
                }
            }
        }
        return res;
    }
};
