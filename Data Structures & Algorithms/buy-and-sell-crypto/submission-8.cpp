class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //[10,1,5,6,7,1,100]
        int buy=0;
        int sell=1;
        int maxProfit=0;
        while(sell<prices.size()){
            if(prices[buy]>prices[sell]){
                buy=sell;
            }else{
                maxProfit = max(maxProfit, prices[sell]-prices[buy]);
            }
            sell+=1;
        }
        return maxProfit;
    }
};
