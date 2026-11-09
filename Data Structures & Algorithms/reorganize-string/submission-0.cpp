class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int>map;
        for(char c: s){
            map[c]+=1;
        }
        priority_queue<pair<int, char>>pq;
        for(pair<char, int>p:map){
            pq.push({p.second, p.first});
        }
        string res;
        pair<int, char> prev = {0, '#'};
        //aaab 
        //a->1         
        //b->0
        //prev={1,a}
        //res="aba"
        //
        while(!pq.empty() || prev!=make_pair(0,'#')){
            if(pq.empty() && prev.first!=0){
                return "";
            }
            pair<int, char>p = pq.top();
            pq.pop();
            res+=p.second;
            p.first-=1;
            if(prev!=make_pair(0,'#')){
                pq.push(prev);
                if(p.first>0){
                    prev=p;
                }else{
                    prev=make_pair(0,'#');
                }
            }else{
                if(p.first>0){
                    prev=p;
                }
                
            }   
        }
        return res;
    }
};