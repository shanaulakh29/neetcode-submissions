class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int maxArea=0;
        while(left<right){
            int area =  min(heights[right],heights[left])* (right-left);
            maxArea = max(area, maxArea);
            if(heights[left]>heights[right]){
                right--;
            }else{
                left++;
            }
        }
        return maxArea;
    }
};
