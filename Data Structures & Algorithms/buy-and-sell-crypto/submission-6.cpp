class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int buy=0;
        int sell=1;
        while(sell<prices.size()){
            if(prices[buy]<prices[sell]){
                int profit = abs(prices[buy]-prices[sell]);
                maxProfit = max(maxProfit, profit);
                sell++;
            }else{
                buy=sell;
                sell++;
            }
        }
        return maxProfit;
    }
};
