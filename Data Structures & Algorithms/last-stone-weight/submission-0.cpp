class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>maxHeap;
        for(int num:stones){
            maxHeap.push(num);
        }
        int size = maxHeap.size();
        while(size>1){
            int val1 = maxHeap.top();
            maxHeap.pop();
            size--;
            int val2 = maxHeap.top();
            maxHeap.pop();
            size--;
            if(val1>val2){
                maxHeap.push(val1-val2);
                size++;
            }else if(val1<val2){
               maxHeap.push(val2-val1); 
               size++;
            }
        }
        if(size==1){
            return maxHeap.top();
        }else{
            return 0;
        }
    }
};
