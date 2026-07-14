class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>set;
        vector<vector<int>> v;
        int n = nums.size();

        for(int i = 0; i < n - 2; i++) {
 
            int j = i + 1;
            int k = n - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    set.insert(vector<int>{nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } 
                else if(sum < 0) {
                    j++;
                } 
                else {
                    k--;
                }
            }
        }
       for (auto triplet : set) {
    v.push_back(triplet);
}
        return v;
    }
};
