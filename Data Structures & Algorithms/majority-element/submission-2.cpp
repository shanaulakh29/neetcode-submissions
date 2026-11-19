class Solution {
public:
//[5,5,1,1,1,3,3,1,1]
//                 L
//count = 1
//res = 1
    int majorityElement(vector<int>& nums) {
        int left=0;
        int res=nums[left];
        int count=1;

        left+=1;
        while(left<nums.size()){
            if(nums[left]==res){
                count+=1;
            }else{
                if(count-1>=0){
                    count-=1;
                }else{
                    count=1;
                    res = nums[left];
                }
            }
            left+=1;
        }
        return res;
    }
};