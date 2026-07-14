class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>output(temperatures.size(),0);
        stack<pair<int,int>>st;
        for(int i=0;i<temperatures.size();i++){
            if(st.empty()){
                st.push(pair(temperatures[i],i));
            }else{
                while(!st.empty() && st.top().first<temperatures[i]){
                    auto p = st.top();
                    st.pop();
                    output[p.second]=i-p.second;
                }
                st.push(pair<int,int>(temperatures[i],i));
            }
        }
        return output;
    }
};
//[38,30]
//[1,]