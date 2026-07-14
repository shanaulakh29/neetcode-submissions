class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,int>mp;
        for(int i=0;i<position.size();i++){
            mp[position[i]]=speed[i];
        }
        stack<float>st;
        for(auto it=mp.rbegin();it !=mp.rend();it++){
            float distance = (float)(target - it->first);
            float time = distance/(float)it->second;
            if(!st.empty() && time <= st.top()){
                continue;
            }
            st.push(time);
        }
        return st.size();
    }
};
