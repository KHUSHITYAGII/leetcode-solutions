class Solution {
public:
    int t[5001][2];
    int solve(int i,int buy,vector<int>&prices){
        if(i >= prices.size()){
            return 0;
        }
        if(t[i][buy] != -1){
            return t[i][buy];
        }
        if(buy == 1){
            return t[i][buy]  = max(-prices[i] + solve(i+1,0,prices),solve(i+1,1,prices));
        }
        else{
            return t[i][buy] = max(prices[i] + solve(i+2,1,prices),solve(i+1,0,prices));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(t,-1,sizeof(t));
        return solve(0,1,prices);
        
    }
};