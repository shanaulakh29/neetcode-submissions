class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set;
        for(int num:nums){
            set.insert(num);
        }
        int maxLength=0;
        int length=0;
        for(int i=0;i<nums.size();i++){
            if(set.contains(nums[i]-1)){
                continue;
            }else{
                length+=1;
                maxLength = max(maxLength, length);
                int inc=1;
                while(set.contains(nums[i]+inc)){
                    length+=1;
                    maxLength = max(maxLength, length);
                    inc+=1;
                }
                length=0;
            }
        }
        return maxLength;

    }
};
