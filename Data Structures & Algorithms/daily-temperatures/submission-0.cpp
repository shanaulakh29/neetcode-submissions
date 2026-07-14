class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int>res;
        for(int i=0;i<size;i++){
            int currElement = temperatures[i];
            int val=0;
            for(int j=i+1;j<size;j++){
                if(currElement<temperatures[j]){
                   val = j-i; 
                   break;
                }          
            }
            res.push_back(val);
        }
        return res;
    }
};
