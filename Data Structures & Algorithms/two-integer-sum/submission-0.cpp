class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> map;
        for(int i=0;i<nums.size();i++){
            int reqNum = target-nums[i];
            if(map.find(reqNum)!=map.end()){
                return vector<int>{map[reqNum], i};
            }else{
                map[nums[i]]=i;
            }
        }

    }
};
