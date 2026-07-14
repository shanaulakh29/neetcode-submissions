class Solution {
    //[-4,-1,-1,-1,0,1,2]
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int i=0;
        while(i<nums.size()){
            if(i>=1 && nums[i]==nums[i-1]){
                i++;
                continue;
            }
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum==0){
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left < right && nums[left]==nums[left+1]){
                        left+=1;
                    }
                    while(right>=0 && nums[right]==nums[right-1]){
                        right-=1;
                    }
                    left+=1;
                    right-=1;     
                }else if(sum<0){
                    left+=1;               
                }else{
                    right-=1;   
                }
            }
            i++;
        }
        return res;
    }
};
