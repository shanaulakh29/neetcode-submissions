class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>set;
        int left=0;
        int right=0;
        int maxLength=0;
        while(right<s.size()){
            while(set.contains(s[right])){
                set.erase(s[left]);
                left++;
            }
            set.insert(s[right]);
            right++;
            int length=right-left;
            maxLength=max(length, maxLength);
        }
        return maxLength;
    }
};
