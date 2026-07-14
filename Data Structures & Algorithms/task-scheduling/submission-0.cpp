class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int,vector<int>>maxheap;
        vector<int>array(26,0);
        for(char c: tasks){
            array[c-'A']+=1;
        }
        for(int num:array){
            if(num>0){
                maxheap.push(num);
            }
        }
        int time=0;
        queue<pair<int,int>>q;
        while(!maxheap.empty() || !q.empty()){
            time++;
            while(!q.empty() && time==q.front().second){
                maxheap.push(q.front().first);
                q.pop();
            }
            if(!maxheap.empty()){
                int val = maxheap.top();
                maxheap.pop();
                val--;
                if(val>0){
                    int taskToBeAvailable = time+n+1;
                    q.push({val,taskToBeAvailable});
                }
            }
        }
        return time;
    }
};
