class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int freq[26] = {0};
        for(char c : s1){
            freq[c - 'a']++;
        }
        int l = 0;
        int r = 0;
        int windowSize = s1.size(); // total characters we need to match

        while (r < s2.size()) {
            // Decrease freq and count if s2[r] is useful
            if (freq[s2[r] - 'a'] > 0) {
                windowSize--;
            }
            freq[s2[r] - 'a']--;

            // If all characters matched
            if (windowSize == 0) return true;

            // If window is larger than s1, slide it
            if (r - l+1 == s1.size()) {
                if (freq[s2[l] - 'a'] >= 0) {
                    windowSize++;  // restoring a matched character
                }
                freq[s2[l] - 'a']++;
                l++;
            }
            r++;
        }

        return false;
    }
};
