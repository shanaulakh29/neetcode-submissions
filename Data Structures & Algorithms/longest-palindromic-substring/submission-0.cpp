class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0){
            return "";
        }
        int maxlen=0;
        int start;
       for(int i=0;i<s.size();i++){
            int left=i;
            int right=i;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                if(maxlen<right-left+1){
                    start=left;
                    maxlen = right-left+1;
                }
                left--;
                right++;
            }
            //for even string
            left=i;
            right=i+1;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                if(maxlen<right-left+1){
                    start=left;
                    maxlen = right-left+1;
                }
                left--;
                right++;
            }
       }
       return s.substr(start,maxlen);
    }
};
