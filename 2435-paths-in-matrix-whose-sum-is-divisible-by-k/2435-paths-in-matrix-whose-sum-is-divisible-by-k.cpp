class Solution {
public:
    int mod = 1e9+7;
    int n, m;
    vector<vector<vector<int> > > dp;
    int solve(vector<vector<int> > &grid, int k, int i, int j, int sum) {
        if(i >= n || j >= m)
            return 0;
        if(i == n-1 && j == m-1) {
            sum += grid[i][j];
            if(sum%k == 0)
                return 1;
            return 0;
        } 
        
        if(dp[i][j][sum%k] != -1)
            return dp[i][j][sum%k];
        
        //down
        int op1 = (solve(grid, k, i+1, j, sum+grid[i][j]))%mod;
        //right
        int op2 = (solve(grid, k, i, j+1, sum+grid[i][j]))%mod;
        
        return dp[i][j][sum%k] = (op1+op2)%mod;
        // return (op1+op2)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        dp.resize(n+1, vector<vector<int> >(m+1, vector<int>(k+1, -1)));
       return solve(grid, k, 0, 0, 0); 
    }
};