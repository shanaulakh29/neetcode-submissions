class Solution {
public:
 vector<int>len;
    string encode(vector<string>& strs) {
        string s;
        for(string str: strs){
            len.push_back(str.size());
            s+=str;
        }
        return s;
    }

    vector<string> decode(string s) {   
        vector<string>res;
        for(int l:len){
            res.push_back(s.substr(0,l));
            s = s.substr(l,s.size());
        }
        return res;
    }
};
