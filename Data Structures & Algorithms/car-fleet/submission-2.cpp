class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float>st;
        map<int,int>map;
        for(int i=0;i<position.size();i++){
            map[position[i]]=speed[i];
        }

        for(auto it=map.rbegin();it!=map.rend();it++){
            float pos = it->first;
            float spee = it->second;
            float time = (target-pos)/spee;
            if(!st.empty() && st.top()>=time){
                continue;
            }else{
               st.push(time);
            }
        }
        return st.size();
    }
};
