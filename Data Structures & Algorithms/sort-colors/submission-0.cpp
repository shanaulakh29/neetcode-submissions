class Solution {
public:
// [0,1,2,2,2,2,2]
//  L             
//      R
//    M               
// if(M==0){
//     swap(L,M)
//     L++
// }
// if(M==2){
//     swap(R,M)
//     R--;
// }
    void swap(vector<int>&nums, int left,int right){
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
    void sortColors(vector<int>& nums) {
        int left=0;
        int mid = 0;
        int right = nums.size()-1;
        while(mid<=right){
            if(nums[mid]==0){
                swap(nums, left, mid);
                left+=1;
                mid+=1;
            }
            else if(nums[mid]==2){
                swap(nums, mid, right);
                right-=1;
            }
            else{
                mid+=1;
            }
        }
    }
};