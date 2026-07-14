class Solution {
    vector<vector<int>>res;
public:
    void dfs(int index,vector<int>& nums, vector<int>& curr, int total, int target){
        if(total==target){
            res.push_back(curr);
            return;
        }
        if(index>=nums.size() || total>target){
            return;
        }
        curr.push_back(nums[index]);
        dfs(index,nums,curr,total+nums[index],target);

        curr.pop_back();
        dfs(index+1,nums,curr,total,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>curr;
        dfs(0,nums,curr,0,target);
        return res;
    }
};
