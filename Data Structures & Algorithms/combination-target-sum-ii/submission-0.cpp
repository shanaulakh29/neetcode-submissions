class Solution {
    vector<vector<int>>res;
public:
    void dfs(int index,vector<int>& candidates, vector<int>& curr, int total, int target){
        sort(candidates.begin(),candidates.end());
        if(total==target){
            res.push_back(curr);
            return;
        }
        if(index>=candidates.size()|| total>target){
            return;
        }
        curr.push_back(candidates[index]);
        dfs(index+1,candidates, curr, total+candidates[index],target);

        curr.pop_back();
        while(index+1<candidates.size() && candidates[index]==candidates[index+1]){
            index+=1;
        }
        dfs(index+1,candidates, curr, total,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
        dfs(0,candidates, curr, 0, target);
        return res;
    }
};
