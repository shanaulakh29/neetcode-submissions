class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum=INT_MIN;
        int sum=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i;j<nums.size();j++){
        //         sum+=nums[j];
        //         maximum = max(maximum,sum);
        //     }
        //     sum=0;
        // }
        for(int i=0;i<nums.size();i++){
            if(sum<0){
                sum=0;
            }
            sum+=nums[i];
            maximum = max(maximum, sum);
        }
        return maximum;
    }
};
