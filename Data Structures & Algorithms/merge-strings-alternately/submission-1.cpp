class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int ptr1=0;
        int ptr2=0;
        if(word1.size()==0){
            return word2;
        }
        if(word2.size()==0){
            return word1;
        }
        while(ptr1<word1.size() && ptr2<word2.size()){
            res+=word1[ptr1];
            ptr1+=1;
            res+=word2[ptr2];
            ptr2+=1;
        }
        if(ptr1<word1.size()){
            res+=word1.substr(ptr1);
        }else if(ptr2<word2.size()){
            res+=word2.substr(ptr2);
        }
        return res;
    }
};