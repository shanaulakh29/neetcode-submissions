class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        unordered_map<int, int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]+=1;
        }
        for(pair<int,int>p:map){
            pq.push({p.second, p.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
