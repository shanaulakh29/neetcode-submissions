class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>set;
        int maxlength=0;
        for(int num:nums){
            if(!set.count(num)){
                set.insert(num);
            }
        }
        for(int num:nums){
            int length=0;
            if(set.contains(num-1)){
                continue;
            }
            while(set.contains(num)){
                length+=1;
                maxlength=max(length,maxlength);
                num=num+1;
            }
        }
        return maxlength;
    }
};
