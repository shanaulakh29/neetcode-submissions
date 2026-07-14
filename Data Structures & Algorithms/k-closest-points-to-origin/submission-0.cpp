class Solution {
public:
    int getDistanceFromOrigin(vector<int>&point){
        int x1=point[0];
        int y1 = point[1];
        return x1*x1+y1*y1;//since x2 and y2 are 0 so the forumla becomes x1^2 +y1^2
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [](pair<int,int>p1,pair<int,int>p2){
            return p1.first>p2.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(compare)>minheap(compare);
        for(int i=0;i<points.size();i++){
            int distance = getDistanceFromOrigin(points[i]);
            minheap.push({distance,i});
        }
        vector<vector<int>>res;
        while(k>0){
            pair<int,int> p = minheap.top();
            res.push_back(points[p.second]);
            minheap.pop();
            k--;
        }

        return res;
    }
};
