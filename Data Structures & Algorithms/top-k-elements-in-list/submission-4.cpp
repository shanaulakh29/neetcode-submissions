class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>>bucket(nums.size()+1);
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]+=1;
        }
        for(auto pair:mp){
            int num=pair.first;
            int freq=pair.second;
            bucket[freq].push_back(num);
        }
        vector<int>res;
        int size=0;
        for(int i=nums.size();i>=0;i--){
            for(int j=0;j<bucket[i].size();j++){
                if(size<k){
                    res.push_back(bucket[i][j]);
                    size++;
                }else{
                    return res;
                }
                
            }
            
        }
        return res;
    }
};
