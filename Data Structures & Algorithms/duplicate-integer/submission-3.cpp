class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> set;
        for(int num:nums){
            if(set.contains(num)){
                return true;
            }
            set.insert(num);
        }
        return false;
    }
};