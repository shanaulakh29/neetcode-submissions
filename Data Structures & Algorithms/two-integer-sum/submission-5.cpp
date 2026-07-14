class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            int diff = target-nums[i];
            if(map.find(diff)==map.end()){
                map[nums[i]]=i;
            }else{
                res.push_back(map[diff]);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};
