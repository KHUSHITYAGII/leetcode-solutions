class Solution {
public:
    int t[13][10001];
    int solve(vector<int>& coins, int amount,int i,int n){

        if(amount == 0) return 0;
        if(i >= n) return 1e9;
        if(amount < 0) return 1e9;

        if(t[i][amount] != -1){
            return t[i][amount];
        }

        int take = 1 + solve(coins,amount-coins[i],i,n);
        int not_take = solve(coins,amount,i+1,n);

        return t[i][amount] =  min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(t,-1,sizeof(t));
        int ans = solve(coins, amount, 0, n);

        if(ans >= 1e9){
            return -1;
        }
        return ans;
        
    }
};