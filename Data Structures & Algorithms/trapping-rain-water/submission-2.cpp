class Solution {
public:
    int trap(vector<int>& height) {
        // if(height.size()==0){
        //     return 0;
        // }
        // vector<int>maxLeft(height.size());
        // vector<int>maxRight(height.size());
        // int maxleft=0;
        // maxLeft[0]=0;
        // for(int i=1;i<height.size();i++){
        //     //[0,0,2,2,3,3,3,3,3,3]
        //     maxleft = max(maxleft,height[i-1]);
        //     maxLeft[i]=maxleft;
            
        // }
        // int maxright=0;
        // maxRight[height.size()-1]=0;
        // for(int i=height.size()-2;i>=0;i--){
        //     //[3,3,3,3,3,3,3,2,1,0]
        //     maxright = max(maxright,height[i+1]);
        //     maxRight[i]=maxright;
        // }
        // vector<int>waterlevel;
        // for(int i=0;i<height.size();i++){
        //     //[0,0,2,2,3,3,3,2,1,0]
        //     waterlevel.push_back(min(maxLeft[i],maxRight[i]));
        // }
        // int res=0;
        // for(int i=0;i<height.size();i++){
        //     //[0,0,2,0,2,3,2,0,0,0]
        //     if(waterlevel[i]-height[i]>0){
        //         res+=waterlevel[i]-height[i];
        //     }
        // }
        // return res;

        int l=0;
        int r = height.size()-1;
        int leftMax = height[l];
        int rightMax = height[r];
        int res=0;
        while(l<r){
            if(leftMax<rightMax){
                l++;
                if(leftMax-height[l]>0){
                    res+=leftMax-height[l];
                }
                leftMax = max(leftMax, height[l]);
            }else{
                r--;
                if(rightMax-height[r]>0){
                    res+=rightMax-height[r];
                }
                rightMax = max(rightMax, height[r]);
            }
        }
        return res;
    }
};
