class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft[height.size()];
        int maxRight[height.size()];
        int minLeftRight[height.size()];
        maxLeft[0]=0;
        maxRight[height.size()-1] = 0; 
        for(int i=1;i<height.size();i++){
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);
        }
        for(int i=height.size()-2;i>=0;i--){
            maxRight[i] = max(maxRight[i+1], height[i+1]);
        }
        for(int i=0;i<height.size();i++){
            minLeftRight[i] = min(maxLeft[i],maxRight[i]);
        }
        int res=0;
        for(int i=0;i<height.size();i++){
            if(height[i]<minLeftRight[i]){
                res+=minLeftRight[i]-height[i];
            }
        }
        return res;
    }
};
