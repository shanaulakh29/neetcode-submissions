class Solution {
public:
//{2,10,30}
//[2,10,30,10,30,30]
//          L             
//                  R  
    int removeDuplicates(vector<int>& nums) {
        int left=0;
        int right=0;
        set<int>s;
        while(right<nums.size()){
            if(!s.contains(nums[right])){
                s.insert(nums[right]);
                if(left!=right){
                    int temp = nums[left];
                    nums[left]= nums[right];
                    nums[right] = temp;
                }
                left+=1;
                continue;    
            } 
            right+=1;
        }
        return left;
    }
};