class Solution {
public:
    int climbStairs(int n) {
       vector<int>v(n+1, 0);
       v[n]=1;
       v[n-1]=1;
       for(int i=n-1;i>0;i--){
            v[i-1] = v[i]+v[i+1];
       }
       return v[0];
    }
};
//5
//[1,2,3,4,5]
