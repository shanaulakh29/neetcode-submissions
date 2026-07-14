class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>set;
        int left=0;
        int right=0;
        int length=0;
        int maxLength=0;
        while(right<s.size()){
            while(set.contains(s[right])){
                set.erase(s[left]);
                left++;
                length=right-left;
            }
            set.insert(s[right]);
            right+=1;
            length = right-left;
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};
