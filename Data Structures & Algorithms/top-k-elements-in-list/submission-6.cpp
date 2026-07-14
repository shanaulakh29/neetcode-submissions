class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        int size = nums.size();
        vector<vector<int>>freq(size+1);
        unordered_map<int,int>map;
        for(int &num:nums){
            map[num]+=1;
        }
        for(auto p:map){
            freq[p.second].push_back(p.first);
        }
        int count=0;
        for(int i=size;i>=0;i--){
            for(int j=0;j<freq[i].size();j++){
                if(count<k){
                    res.push_back(freq[i][j]);
                    count++;
                }
            }
        }
        return res;
    }
};
