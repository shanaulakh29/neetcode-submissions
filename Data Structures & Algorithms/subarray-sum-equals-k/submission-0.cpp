class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>map;
        for(int i=0;i<nums.size();i++){
            int runningSum=nums[i];
            if(runningSum==k){
                map[k]+=1;
            }
            for(int j=i+1;j<nums.size();j++){
                runningSum+=nums[j];
                if(runningSum==k){
                    map[k]+=1;
                }
            }
        }
        return map[k];
    }
};