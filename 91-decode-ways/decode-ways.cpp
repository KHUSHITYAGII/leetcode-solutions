class Solution { 
public: 
    int t[101];
    int solve(string s, int i, int n) { 
        
        if(i >= n) { 
            return t[i] =  1; 
        } 
        
        if(s[i] == '0') { 
            return t[i] =  0; 
        }
        if(t[i] != -1){
            return t[i];
        }
        
        int only_ith_take = solve(s, i + 1, n); 
        int ith_onePlus_take = 0; 
 
        if(i + 1 < n && (s[i] == '1' || 
            (s[i] == '2' && s[i + 1] <= '6'))) { 
            
            ith_onePlus_take = solve(s, i + 2, n); 
        } 
 
        return t[i] = only_ith_take + ith_onePlus_take; 
    } 
    
    int numDecodings(string s) { 
        int n = s.size(); 
        memset(t,-1,sizeof(t));
        if(n == 0) 
            return 0; 
 
        return solve(s, 0, n); 
    } 
};