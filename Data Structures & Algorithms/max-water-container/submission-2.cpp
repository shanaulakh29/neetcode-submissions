class Solution {
public:
    int maxArea(vector<int>& heights) {
        // int area=0;
        // for(int i=0;i<heights.size();i++){//O(n^2)
        //     for(int j=i+1;j<heights.size();j++){
        //         int l = min(heights[i],heights[j]);
        //         int b = j-i;
        //         int res = l*b;
        //         area = max(area,res);
        //     }
        // }
        // return area;
        int l=0;
        int r=heights.size()-1;
        int area = 0;
        while(l<r){//O(n) time
            int length = min(heights[l],heights[r]);
            int bredth = r-l;
            int res = length*bredth;
            area = max(area,res);
            if(heights[l] < heights[r]){
                l++;
            }else if(heights[l] > heights[r]){
                r--;
            }else{//when heights[l] = heights[r] shift either l or r doesnt matter
                l++;
            }
        }
        return area;
    }
};
