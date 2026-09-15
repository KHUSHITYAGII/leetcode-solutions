class Solution {
public:
    int t[201][201];
    bool visited[201][201];

    int solve(int i, int j, vector<vector<int>>& triangle) {

        if(i == triangle.size() - 1) {
            return triangle[i][j];
        }

        if(visited[i][j]) {
            return t[i][j];
        }

        int down = solve(i + 1, j, triangle);
        int diagonal = solve(i + 1, j + 1, triangle);

        visited[i][j] = true;

        return t[i][j] = triangle[i][j] + min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        memset(visited, false, sizeof(visited));

        return solve(0, 0, triangle);
    }
};