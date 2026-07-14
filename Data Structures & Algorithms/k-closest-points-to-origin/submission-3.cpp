class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, less<pair<int, vector<int>>>>pq;
        for(vector<int>&point:points){
            int x = point[0];
            int y = point[1];
            int distance = (x*x) + (y*y);
            pq.push(pair<int, vector<int>>(distance, vector<int>{x,y}));
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>res;
        int temp=0;
        while(temp!=k){
            res.push_back(pq.top().second);
            pq.pop();
            temp+=1;
        }
        return res;
    }
};
