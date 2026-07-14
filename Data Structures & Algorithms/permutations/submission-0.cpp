class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==1){
            return {nums};
        }
        vector<int>rest(nums.begin()+1,nums.end());
        vector<vector<int>>perms = permute(rest);
        vector<vector<int>>res;
        for(vector<int>p:perms){
            for(int i=0;i<p.size()+1;i++){
                vector<int> temp = p; // make a copy
                temp.insert(temp.begin() + i, nums[0]);
                res.push_back(temp);
            }
            
        }
        return res;
    }
};
