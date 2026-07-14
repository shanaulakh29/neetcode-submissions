class Solution {
public:
    bool dfs(int node, unordered_map<int,vector<int>>&map, vector<int>&state){
        if(state[node]==1){
            return false;
        }
        if(state[node]==2){
            return true;
        }
        state[node]=1;
        for(int &v:map[node]){
            if(!dfs(v, map, state)){
                return false;
            }
        }
        state[node]=2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //[0,1],[2,1],[3,0],[4,2],[0,3]
        //0->[1,3,4]
        //1->[]
        //2->[1]
        //3->[]
        //4->[]
        //5->[3]
        unordered_map<int,vector<int>>map;
        for(auto preq:prerequisites){
            map[preq[0]].push_back(preq[1]);
        }
        vector<int>state(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!dfs(i,map,state)){
                return false;
            }

        }
        return true;
    }
};
