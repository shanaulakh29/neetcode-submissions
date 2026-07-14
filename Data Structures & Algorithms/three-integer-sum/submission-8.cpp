class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int target=0-nums[i];
            int left=i+1;
            int right= nums.size()-1;
            while(left<right){
                int sum = nums[left]+nums[right];
                if(sum<target){
                    left+=1;
                }else if(sum>target){
                    right-=1;
                }else{
                    res.push_back(vector<int>{nums[left],nums[right],nums[i]});
                    while(left+1<nums.size() && nums[left]==nums[left+1]){
                        left++;
                    }
                    while(right-1>=0 && nums[right]==nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
