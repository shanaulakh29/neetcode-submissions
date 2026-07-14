class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]+=1;
        }
        vector<vector<int>>freq(nums.size()+1);
        for(auto & pair:map){
            freq[pair.second].push_back(pair.first);
        }
        vector<int>res;
        for(int i=freq.size()-1;i>=0;i--){
            if(k==0){
                break;
            }
            if(freq[i].size()==0){
                continue;
            }
            for(int j=0;j<freq[i].size() && k>0 ;j++){
                res.push_back(freq[i][j]);
                k--;
            }
        }
        return res;
    }
};
