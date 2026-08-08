class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        int freq[26]={0};
        //calculate frequency of each task
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']+=1;
        }
        //populate maxheap with each task frequency
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                pq.push(freq[i]);
            }
        }
        int time=0;
        while(!pq.empty()|| !q.empty()){
            time+=1;
            if(!pq.empty()){
                int taskFreq = pq.top();
                pq.pop();
                taskFreq-=1;
                if(taskFreq>0){
                    q.push(pair<int,int>{taskFreq, time+n});
                }     
            }
            if(!q.empty() && time==q.front().second){
                pq.push(q.front().first);
                q.pop();
            }
            
        }
        return time;

    }
};
