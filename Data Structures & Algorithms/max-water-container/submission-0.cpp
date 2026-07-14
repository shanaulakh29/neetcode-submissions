class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area=0;
        for(int i=0;i<heights.size();i++){//O(n^2)
            for(int j=i+1;j<heights.size();j++){
                int l = min(heights[i],heights[j]);
                int b = j-i;
                int res = l*b;
                area = max(area,res);
            }
        }
        return area;
    }
};
