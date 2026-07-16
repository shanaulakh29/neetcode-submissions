class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //hzkezrtyuiop
        unordered_set<char> set;
        int left=0;
        int right=0;
        int maxLength=0;
        while(right<s.size()){
            while(set.contains(s[right])){
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            maxLength=max(maxLength, right-left+1);
            right++;
        }
        return maxLength;
    }
};
