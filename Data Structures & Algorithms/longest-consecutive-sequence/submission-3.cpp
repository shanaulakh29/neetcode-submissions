class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set;
        for(int num:nums){
            set.insert(num);
        }
        int maxLength=0;   
        for(int&num:nums){
            int length=0;
            while(set.contains(num)){
                length+=1;
                maxLength = max(length, maxLength);
                num=num-1;
            }
        }
        return maxLength;
    }
};
