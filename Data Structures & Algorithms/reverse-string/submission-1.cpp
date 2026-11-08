class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0;
        int right = s.size()-1;
        while(left<right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left+=1;
            right-=1;
        }
        // unordered_map<int, char>map;
        // for(int i=0;i<s.size();i++){
        //     map[i]=s[i];
        // }
        // vector<char>res(s.size());
        // int size = s.size()-1;
        // int j=0;
        // for(int i=size;i>=0;i--){
        //     res[j] = map[i];
        //     j+=1;
        // }
        // s = res;
    }
};