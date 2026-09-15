class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minBuy = prices[0];

        for(int i = 1;i < n;i++){
            if(prices[i] < minBuy){
                minBuy = prices[i];
            }
            int profit = prices[i]-minBuy;
            maxProfit = max(maxProfit,profit);
        }
        return maxProfit;
    }
};