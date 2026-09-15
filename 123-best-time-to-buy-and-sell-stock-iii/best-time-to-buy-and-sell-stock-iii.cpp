class Solution {
public:
    int t[100005][2][3];
    int solve(int i,int buy , int cap,vector<int>& prices){
        if(i == prices.size() || cap == 0){
            return 0;
        }
        if(t[i][buy][cap] != -1){
            return t[i][buy][cap];
        }
        if(buy){
            return t[i][buy][cap] = max(
                -prices[i] + solve(i+1,0,cap,prices),
                solve(i+1,1,cap,prices)
            );
        }
        else{
            return t[i][buy][cap] = max(prices[i] + solve(i+1,1,cap-1,prices),solve(i+1,0,cap,prices)
            );
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(t,-1,sizeof(t));
        return solve(0,1,2,prices); 
    }
};