class Solution {
public:
    bool canShip(vector<int>& weights, int capacity, int days){
        int shipsRequired = 1;
        int runningWeight =0;
        for(int i=0;i<weights.size();i++){
            if(runningWeight+weights[i]>capacity){
                shipsRequired+=1;
                runningWeight=0;
            }
            runningWeight+=weights[i];
        }
        return shipsRequired<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int result = INT_MAX;
        int left = INT_MIN;
        int right=0;
        for(int i=0;i<weights.size();i++){
            left = max(left, weights[i]);
            right+=weights[i];
        }
        while(left<=right){
            int capacity = left+(right-left)/2;
            if(canShip(weights,capacity, days)){
                result = min(result, capacity);
                right = capacity-1;
            }else{
                left+=1;
            }
        }
        return result;
    }
};