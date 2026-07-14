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
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        for(int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            graph[prereq].push_back(course);
            inDegree[course]++;
        }
        
        // Start with courses that have no prerequisites
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Process courses one by one
        int coursesCompleted = 0;
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            coursesCompleted++;
            
            // Remove this course as a prerequisite for others
            for(int i = 0; i < graph[current].size(); i++) {
                int nextCourse = graph[current][i];
                inDegree[nextCourse]--;
                
                // If all prerequisites are done, add to queue
                if(inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        // If we completed all courses, no cycle exists
        return coursesCompleted == numCourses;
    }

};
