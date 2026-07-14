class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //[-4,-1,-1,-1,0,1,2]
        vector<vector<int>>res;
        for(int i=0;i<nums.size();i++){
            if(i>=1 && nums[i]==nums[i-1]){
                continue;
            }

            int left=i+1;
            int right=nums.size()-1;
            
            while(left<right){
                int sum=nums[left]+nums[right]+nums[i];
                if(sum < 0){
                    left+=1;
                    while(left<right&& nums[left]==nums[left-1]){
                        left+=1;
                    }
                }else if(sum > 0){
                    right-=1;
                    while(left<right && nums[right]==nums[right+1]){
                        right-=1;
                    }
                }else{
                    res.push_back({nums[i],nums[left],nums[right]});
                    left+=1;
                    right-=1;
                    while(left<right&& nums[left]==nums[left-1]){
                        left+=1;
                    }
                    while(left<right && nums[right]==nums[right+1]){
                        right-=1;
                    }
                }
            }
        }
        return res;
    }
};
