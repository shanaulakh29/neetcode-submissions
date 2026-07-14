class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int num:nums){
            if(map.find(num)!=map.end()){
                return true;
            }else{
                map[num]+=1;
            }
        }
        return false;

    }
};
