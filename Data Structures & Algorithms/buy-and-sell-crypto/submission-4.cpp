class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int L=0;
        int R=L+1;
        int maxProfit = 0;
        while(R < prices.size()){
            if(prices[L]>prices[R]){
                L=R;
                R++;
                continue;
            }else if(prices[L]<=prices[R]){
                int currentProfit = prices[R]-prices[L];
                maxProfit = std::max(maxProfit, currentProfit);
                R++;
            }
        }
        return maxProfit;
    }
};
