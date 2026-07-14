class Solution {
public:
    double getDistanceFromOrigin(vector<int>&point){
        double x=point[0];
        double y=point[1];
        return sqrt(x*x+y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>>maxheap;
        for(auto point:points){
            double distance = getDistanceFromOrigin(point);
            maxheap.push(pair<double, vector<int>>{distance, point});
            if(maxheap.size()>k){
                maxheap.pop();
            }
        }
        vector<vector<int>>res;
        while(!maxheap.empty()){
            auto pair = maxheap.top();
            maxheap.pop();
            res.push_back(pair.second);
        }
        return res;
    }
};
