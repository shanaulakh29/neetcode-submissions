class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int maxArea=0;
        while(left<right){
            int length = min(heights[left],heights[right]);
            int bredth=right-left;
            int area=length*bredth;
            maxArea = max(area,maxArea);
            if(heights[left]<heights[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};
