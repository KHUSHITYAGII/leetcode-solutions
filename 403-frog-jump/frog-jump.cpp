class Solution {
public:
    unordered_map<int,int>mp;
    int t[2001][2001];
    bool solve(int currStone,int prevJump,vector<int>& stones){
        if(currStone == stones.size()-1){
            return true;
        }
        if(t[currStone][prevJump] != -1){
            return t[currStone][prevJump];
        }
        bool result = false;

        for(int nextJump = prevJump-1 ; nextJump <= prevJump+1;nextJump++){
            if(nextJump > 0){
            int nextStone = stones[currStone] +nextJump;
            if(mp.find(nextStone) != mp.end()){
                result  = result || solve(mp[nextStone],nextJump,stones);
                    }
                }
            }
        return t[currStone][prevJump] = result;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        memset(t,-1,sizeof(t));
         if(stones[1] != 1){
            return false;
        }
        for(int i=0;i<n;i++){
            mp[stones[i]] = i;
        }
        return solve(0,0,stones);
    }
};