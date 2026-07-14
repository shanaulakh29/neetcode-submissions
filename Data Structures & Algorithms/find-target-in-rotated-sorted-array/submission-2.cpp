class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r = nums.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(target==nums[mid]){
                return mid;
            }
            if(nums[mid]>=nums[l]){
                if(target < nums[l] || target > nums[mid]){
                    l=mid+1;
                }else if(target>=nums[l] && target < nums[mid]){
                    r=mid-1;
                }
            }else{
                if(target>nums[r] || target < nums[mid]){
                    r=mid-1;
                }else if(target>nums[mid]){
                    l=mid+1;
                }
            }
        }
        return -1;
    }
};
/*
while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[l]<=nums[r]){
                int innerL=l;
                int innerR=r;
                int innerMid = innerL+(innerR-innerL)/2;
                if(nums[innerMid]>target){
                    innerR=innerMid-1;
                }else if(nums[innerMid]<target){
                    innerL=innerMid+1;
                }else{
                    res = innerMid;
                }
            }
            if((nums[mid]>=nums[l] && nums[mid]>target) || (nums[mid]<=nums[l] && target < nums[l])){
                l=mid+1;
            }else if(nums[mid]<=nums[l] && target >=nums[l]){
                r=mid-1;
            }
        }
        return res;*/