class Solution {
public:
    int t[401][101];
    int solve(int i,vector<int>&nums){
        int n = nums.size();
        if( i >= nums.size()) return 0;
        if(t[i][n] != -1){
            return t[i][n];
        }
        int steal = nums[i] + solve(i+2,nums);
        int skip = solve(i+1,nums);

        return t[i][n]  = max(steal,skip);
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,nums);
        
    }
};