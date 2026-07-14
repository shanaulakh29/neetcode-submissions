class Solution {
    vector<vector<int>>res;
public:
    void dfs(vector<int>&nums, vector<int>&curr, int index){
        if(index>=nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[index]);
        dfs(nums,curr,index+1);
        curr.pop_back();
        dfs(nums,curr,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        dfs(nums,curr,0);
        return res;
    }
};
