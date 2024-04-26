class Solution {
public:
    int n;
    vector<vector<int> > dp;
    int solve(vector<vector<int> > &grid, int i, int j) {
        if(i == n-1)
            return grid[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int res = INT_MAX;
        for(int k=0; k<n; k++) {
            if(k != j)
                res = min(res, grid[i][j] + solve(grid, i+1, k));
        }
        return dp[i][j] = res;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        int ans = INT_MAX;
        dp.resize(n, vector<int>(n, -1));
        
        for(int i=0; i<n; i++) {
            ans = min(ans, solve(grid, 0, i));
        }
        return ans;
    }
};