class Solution {
public:
    bool dfs(int course,unordered_map<int,vector<int>>&mp, vector<int>&state){
       if(state[course]==1){
        return false;
       }
       if(state[course]==2){
        return true;
       }
       state[course]=1;
       vector<int>preq = mp[course];
       for(int i=0;i<preq.size();i++){
        
        if(!dfs(preq[i],mp, state)){
            return false;
        }
       }
       state[course]=2;
       return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>state(numCourses, 0);//0 for unvisited, 1 for visiting, 2 for visited
        unordered_map<int,vector<int>>mp;
        for(auto preq:prerequisites){
            mp[preq[0]].push_back(preq[1]);

        }
        for(int i=0;i<numCourses;i++){
            if(!dfs(i,mp, state)){
                return false;
            }
        }
        return true;
    }
};
