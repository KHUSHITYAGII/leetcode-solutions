class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();

        sort(begin(g),end(g));
        sort(begin(s),end(s));
        int count=0;
        int i=0,j=0;

        while( i < m && j < n){
            if(s[j] >= g[i]){
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};