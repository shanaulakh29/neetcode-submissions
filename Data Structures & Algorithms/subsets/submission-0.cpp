class Solution {
    vector<vector<int>>res;
    vector<int>subset;
public:
    void dfs(int index, vector<int>& nums, vector<int>& subset){
        if(index>=nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        dfs(index+1, nums, subset);

        subset.pop_back();
        dfs(index+1, nums, subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums, subset);
        return res;
    }
};
