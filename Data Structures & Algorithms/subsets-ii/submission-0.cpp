class Solution {
vector<vector<int>> res;
public:
    void dfs(vector<int>&nums, vector<int>&curr, int index){

        if(index>=nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        dfs(nums,curr,index+1);

        curr.pop_back();
        while(index+1<nums.size() && nums[index]==nums[index+1]){
            index+=1;
        }
        dfs(nums,curr, index+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>curr;
        sort(nums.begin(),nums.end());
        dfs(nums,curr, 0);
        return res;

    }
};
