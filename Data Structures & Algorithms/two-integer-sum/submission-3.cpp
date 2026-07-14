class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>mp;
       for(int i=0;i<nums.size();i++){
            int val = target - nums[i];
            if(mp.find(val)==mp.end()){
                mp[nums[i]]=i;
            }else{
                return vector<int>{mp[val],i};
            }
       }
    }
};
