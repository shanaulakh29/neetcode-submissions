class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>>pq;
        for(vector<int>&point: points){
            int x = point[0];
            int y=point[1];
            int distance = x*x+y*y;
            pq.push(pair<int, vector<int>>{distance, point});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>res;

        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
