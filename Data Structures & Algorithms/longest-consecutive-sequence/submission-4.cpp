class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int maxLength=0;
     unordered_set<int>set;
     for(int& num:nums){
        set.insert(num);
     }
     for(int i=0;i<nums.size();i++){
        int length=0;
        if(set.contains(nums[i]-1)){
            continue;
        }else{
            length+=1;
            maxLength = max(length, maxLength);
            int nextNum=nums[i]+1;
            while(set.contains(nextNum)){
                length+=1;
                maxLength = max(length, maxLength);
                nextNum+=1;
            }
        }
     }
     return maxLength;
    }

};
