class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]+=1;
        }
        for(pair<const int,int>p:map){
            int key = p.first;
            int value = p.second;
            pq.push({value, key});
            if(pq.size()>k){
                pq.pop();
            }    
        }
        vector<int>res;
        int size = 0;
        while(size!=k){
            res.push_back(pq.top().second);
            pq.pop();
            size++;
        }
        return res;
        // unordered_map<int,int>map;
        // for(int i=0;i<nums.size();i++){
        //     map[nums[i]]+=1;
        // }
        // vector<vector<int>>freq(nums.size()+1);
        // for(auto & pair:map){
        //     freq[pair.second].push_back(pair.first);
        // }
        // vector<int>res;
        // for(int i=freq.size()-1;i>=0;i--){
        //     if(k==0){
        //         break;
        //     }
        //     if(freq[i].size()==0){
        //         continue;
        //     }
        //     for(int j=0;j<freq[i].size() && k>0 ;j++){
        //         res.push_back(freq[i][j]);
        //         k--;
        //     }
        // }
        // return res;
    }
};
