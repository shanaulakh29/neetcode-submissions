class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int val:nums){//O(n)
            mp[val]+=1;
        }
        vector<vector<int>>bucket(nums.size()+1);
        for(auto pair: mp){//O(n)
            int key = pair.first;
            int frequency = pair.second;
            bucket[frequency].push_back(key);
        }
        vector<int>res;
        for(int i=nums.size();i>=0;i--){
            if(bucket[i].size()!=0){
                for(int j=0;j<bucket[i].size();j++){
                    res.push_back(bucket[i][j]);
                }
            }
        if(res.size()==k){
            break;
        }
        }
        return res;
    }
};
