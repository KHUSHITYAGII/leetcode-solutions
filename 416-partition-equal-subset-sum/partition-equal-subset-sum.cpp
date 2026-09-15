class Solution {
public:
    int t[201][20001];
    bool solve(int i,vector<int>& nums,int target){
        if(target == 0){
            return true;
        }
        if(i == nums.size() || target < 0){
            return false;
        }
        if(t[i][target] != -1){
            return t[i][target];
        }
        bool take = solve(i+1,nums,target-nums[i]);
        bool not_take = solve(i+1,nums,target);

        return t[i][target] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        memset(t,-1,sizeof(t));
        return solve(0,nums,sum/2);
        
    }
};