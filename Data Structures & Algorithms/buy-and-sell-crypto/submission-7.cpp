class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0;
        int sell=buy+1;
        int maxProfit=0;
        while(sell<prices.size()){
            if(prices[buy]>prices[sell]){
                buy=sell;
                sell+=1;
            }else{
                int profit=prices[sell]-prices[buy];
                maxProfit = max(maxProfit, profit);
                sell+=1;
            }
        }
        return maxProfit;
    }
};
