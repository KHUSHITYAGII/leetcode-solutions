class Solution {
public:
    void solve(vector<int>& candidates, int target,int i,vector<int>&temp,vector<vector<int>>&ans){
            if(target == 0){
                ans.push_back(temp);
                return ;
            }

            if(target < 0 || i >= candidates.size()){
                return;
            }
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1,temp,ans);
            temp.pop_back();
            
            int j = i + 1;
            while(j < candidates.size() && candidates[j] == candidates[i]) {
            j++;
            }
        solve(candidates, target, j, temp, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>temp;
        vector<vector<int>>ans;

        solve(candidates,target,0,temp,ans);

        return ans;
        
    }
};