class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        unordered_map<int,int>mp;
        unordered_map<int,int>mp2;
        for(int n:nums){
            mp[n]=1;
        }
        vector<int>seqStartNums;
        for(int n:numSet){
            if(mp.find(n-1)==mp.end()){
                seqStartNums.push_back(n);
            }
        }
        for(int n: seqStartNums){
            for(int i=0;i<numSet.size();i++){
                if(mp.find(n+i)==mp.end()){
                   break;
                }else{
                mp2[n]+=1;
                }
            }
        }
        int res = 0;
        for(auto pair:mp2){
            if(res<pair.second){
                res=pair.second;
            }
        }
        return res;
    }
};
