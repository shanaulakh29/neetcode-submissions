class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        unordered_map<char, int>t_map;
        unordered_map<char, int>s_map;
        vector<pair<string, int>>res;
        int matches=0;
        for(int i=0;i<t.size();i++){
            t_map[t[i]]+=1;
        }
        int left=0;
        int right=0;
        while(right<s.size()){
            s_map[s[right]]+=1;
            if(t_map.find(s[right])!=t_map.end()){
                if(s_map[s[right]]==t_map[s[right]]){
                    matches+=1;
                }
            }
            right++;
            if(res.size()==0 && matches==t_map.size()){
                string str= s.substr(left, right);
                res.push_back({str, right-left});
            } 
            while(matches==t_map.size()){                   
                s_map[s[left]]-=1;        
                if(t_map.find(s[left])!=t_map.end()){
                    if(s_map[s[left]]<t_map[s[left]]){
                        matches-=1;
                    }
                }
                left+=1;
                if(matches==t_map.size()){
                    string str = s.substr(left,right-left);
                    if(res[0].second>right-left){
                        res[0]={str, right-left};
                    } 
                }            
            }         
        }

        if(res.size()==1){
            return res[0].first;
        }else{
            return "";
        }
    }
};
