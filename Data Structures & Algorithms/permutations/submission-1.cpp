class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>perms = {{}};
        for(int n: nums){
            vector<vector<int>> newPerms; 
            for(vector<int>p:perms){
                for(int i=0;i<p.size()+1;i++){
                    vector<int>temp = p;
                    temp.insert(temp.begin()+i,n);
                    newPerms.push_back(temp);
                }
            }
            perms = newPerms;
        }
        return perms;

        // if(nums.size()==0){
        //     return vector<vector<int>>(1);
        // }
        // vector<int>rest(nums.begin()+1,nums.end());
        // vector<vector<int>>perms = permute(rest);
        // vector<vector<int>>res;
        // for(vector<int>p:perms){
        //     for(int i=0;i<p.size()+1;i++){
        //         vector<int> temp = p; // make a copy
        //         temp.insert(temp.begin() + i, nums[0]);
        //         res.push_back(temp);
        //     }
        // }
        // return res;
    }
};
