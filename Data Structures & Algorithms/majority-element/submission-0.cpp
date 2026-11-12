class Solution {
public:
//[5,5,1,1,1,5,5]
//             L
//count=1
//res = 5
// if(res==L){
//     count+=1;
// }else{
//     count-=1;
// }
// if(count==-1){
//     res = L
//     count=1;
// }
    int majorityElement(vector<int>& nums) {
        int result = nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==result){
                count+=1;
            }else{
                count-=1;
            }
            if(count==-1){
                result = nums[i];
                count=1;
            }
        }
        return result;
    }
};