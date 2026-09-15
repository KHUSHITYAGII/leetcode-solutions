class Solution {
public:
    int t[50001][2];
    int solve(int i,int buy,vector<int>& prices, int &fee){
        if(i == prices.size()){
            return 0;
        }
        if(t[i][buy] != -1){
            return t[i][buy];
        }
        if(buy == 1){
            return  t[i][buy] =max(-prices[i]+solve(i+1,0,prices,fee),solve(i+1,1,prices,fee));
        }
        else{
            return t[i][buy] = max(prices[i] - fee +solve(i+1,1,prices,fee),solve(i+1,0,prices,fee));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        memset(t,-1,sizeof(t));
        return solve(0,1,prices,fee);
        
    }
};