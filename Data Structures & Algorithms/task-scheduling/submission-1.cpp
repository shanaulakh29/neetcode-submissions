class Solution {
public:
//the motive is to first get the frequency of each task.
//then store the integer frequencies in maxheap that are greater than 0
//at each time tick we take the task from the maxheap if maxheap not empty and we decrement that task frequency. Then we store the task along with its toBeAvaialble time in the queue so that when the time = toBeAvaialble we pop that task from queue and push it in maxHeap to be processed by the cpu.
//
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int,vector<int>>maxheap;
        vector<int>freq(26,0);
        for(char c: tasks){
            freq[c-'A']+=1;
        }
        for(int num:freq){
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
