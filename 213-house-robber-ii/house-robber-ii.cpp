class Solution {
public:
int t[1001][1001];
    int solve(vector<int>& nums,int i,int n){
        if(i >= n) return 0;

        if(t[i][n] != -1){
            return t[i][n];
        }

        int take = nums[i] + solve(nums,i+2,n);
        int skip = solve(nums,i+1,n);

        return t[i][n] = max(take,skip);
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
         if(n == 1) return nums[0];
        if(n == 2) return max(nums[1],nums[0]);
        //case-1
        memset(t,-1,sizeof(t)); 
        int case1 = solve(nums,0,n-1); 
        //case-2
        memset(t,-1,sizeof(t));
        int case2 = solve(nums,1,n);

        return max(case1,case2); 

    }
};