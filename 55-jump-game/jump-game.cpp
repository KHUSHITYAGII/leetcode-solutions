class Solution {
public:
    int t[10001];
    bool solve(vector<int>&nums,int i){
        int n = nums.size();
        if(i >= n-1){
            return true;
        }
        if(t[i] != -1) {
            return t[i];
        }

        for(int jump =1;jump<=nums[i];jump++){
            if(solve(nums,i+jump)){
                return  t[i] = 1;
            }
        }
        return t[i] = 0;
    }
    bool canJump(vector<int>& nums){
        memset(t,-1,sizeof(t));
       return solve(nums,0);
    }
};