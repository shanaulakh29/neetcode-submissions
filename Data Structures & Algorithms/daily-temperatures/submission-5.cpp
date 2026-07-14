class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
         int size = temperatures.size();
         vector<int>res(size,0);
        // for(int i=0;i<size;i++){//O(n^2) time
        //     int currElement = temperatures[i];
        //     int val=0;
        //     for(int j=i+1;j<size;j++){
        //         if(currElement<temperatures[j]){
        //            val = j-i; 
        //            break;
        //         }          
        //     }
        //     res.push_back(val);
        // }
        // return res;

        stack<int>st;
        for(int i=size-1;i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(!st.empty()){
                res[i]=st.top()-i;
            }
            st.push(i);
            }
        return res;
    }
};
