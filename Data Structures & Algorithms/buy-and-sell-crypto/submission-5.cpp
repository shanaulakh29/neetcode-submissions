class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int left=0;
        int right = left+1;
        while(right<prices.size()){//O(n) space:O(1)
        //Here left is buy and right is sell so we check if buy<sell and we calculate max profit.
        //if left(buy) is > right(sell) then we update buy to be = sell as we excountered new lowest price
            if(prices[left]<prices[right]){
                maxProfit = max(maxProfit,prices[right]-prices[left]);
                right++;
            }else{
                left = right;
                right++;
            }
        }
        return maxProfit;
    }
};
