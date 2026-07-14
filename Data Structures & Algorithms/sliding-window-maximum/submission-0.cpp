class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // int l=0;
        // int r=k-1;
        // vector<int>list;
        // while(r<nums.size()){//O(nk)
        //     int maxValue=INT_MIN;
        //     for(int i=l;i<=r;i++){
        //         maxValue = max(maxValue, nums[i]);
        //     }
        //     list.push_back(maxValue);
        //     l++;
        //     r++;
        // }
        // return list;
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()<i-k+1){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
