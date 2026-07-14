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
        for(int i=0;i<nums.size();i++){//space O(k) since at any index the max values inside dq are atmost k
        //time complexity O(n) since we traverse through the nums array linearly. the inner loop doesnt add much to it. or we can say intotal we run the outer loop for n times and also there can be atmost n insert or delete operations in the dq using inner which loop so total time complexity is O(n)+O(n)= O(n)
        //if the first element of the dq is out of bounds thenr remove that index.
        //like if suppose i=3 and k=3, this means element at index 0 is not in current window so remove that element
            if(!dq.empty() && dq.front()<i-k+1){
                dq.pop_front();
            }
        //we are storing in decreasing order. so while inserting we compare if the value at the last is < value at current index, this means it is an increasing order, so we continue to remove the values at back until we either reach empty dq or a greater value at back then the current value
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            //we then insert the index of current value
            dq.push_back(i);
            //and once i>=3 which means we have the minumum window size, we start adding the max elements in the ans array. again, indexes are stored in decreasing format of values at those indexes. so we extract the value at the corresponding index.
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
