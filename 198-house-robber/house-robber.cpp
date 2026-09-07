class Solution {
public:
    int t[400];
    int solve(vector<int>&nums,int i){
        int n = nums.size();
        if(i >= n ) return 0;
        if(n == 1) return nums[i];
        if(n == 2) max(nums[i],nums[i+1]);

        if(t[i] != -1){
            return t[i];
        }

        int take = nums[i] + solve(nums,i+2);
        int skip = solve(nums,i+1);

        return t[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0);
    }
};