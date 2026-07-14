class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;
        int maxFrequency=0;
        int frequency[26]={0};
        int windowSize=0;
        while(right<s.size()){
            frequency[s[right]-'A']+=1;
            maxFrequency = max(maxFrequency, frequency[s[right]-'A']);
            windowSize = right-left+1;
            while(windowSize-maxFrequency>k){
                frequency[s[left]-'A']-=1;
                left+=1;
                windowSize = right-left+1;
            }
            right+=1;
        }
        return windowSize;
    }
    // XYYX
    // A->frequency[A]=1,windowSize=1 1-1!>1
    // A->frequency[A]=2,windowSize=2 2-2!>1
    // A->frequency[A]=3,windowSize=3 3-3!>1
    // B->frequency[B]=1,windowSize=4 4-3!>1
    // A->frequency[A]=4,windowSize=5 5-4!>1
    // B->frequency[B]=2,windowSize=6 6-4>1
    // B->frequency[B]=2,windowSize=4 4-2!>2
};
