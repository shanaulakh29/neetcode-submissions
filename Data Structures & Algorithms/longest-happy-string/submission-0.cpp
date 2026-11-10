class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});   
        pair prev=make_pair(0,'#');
        string res;

        //b
        while(!pq.empty()|| prev.first!=0){
            if(pq.empty() && prev.first>0){
                return res;
            }
            pair<int,char>current = pq.top();
            pq.pop();
            res+=current.second;
            current.first-=1;
            int size = res.size();
            if(prev.first>0){
                pq.push(prev);
                prev=make_pair(0,'#');
            }
            if(current.first>0){
                if(size>=2 && res[size-1]==res[size-2]){
                    prev = current;
                }else{
                    pq.push(current);
                }
            }
            
        }
        return res;
    }
};