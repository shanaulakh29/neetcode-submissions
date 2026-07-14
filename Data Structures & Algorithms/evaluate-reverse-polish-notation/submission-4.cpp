class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int res;
        for(string token: tokens){
            if(token=="+"|| token=="-"|| token=="*"|| token=="/"){
                int val1=s.top();
                s.pop();
                int val2=s.top();
                s.pop();
                if(token=="+"){
                res = val1+val2;
                }else if(token=="-"){
                res = val2-val1;
                }else if(token=="*"){
                res = val1*val2;
                }
                else if(token=="/"){
                res = val2/val1;
                }
                s.push(res);
            }else{
               s.push(stoi(token)); 
            }   
        }
        res=s.top();
        s.pop();
        return res;
    }
};