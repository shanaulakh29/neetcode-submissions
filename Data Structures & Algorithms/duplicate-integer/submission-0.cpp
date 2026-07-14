class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]]>=1){
                return true;
            }
            map[nums[i]]+=1;
        }
        return false;
    }
};
