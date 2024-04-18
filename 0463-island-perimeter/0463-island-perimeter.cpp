class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    int temp = 0;
                    if(i > 0 && grid[i-1][j] == 1)
                        temp++;
                    if(j > 0 && grid[i][j-1] == 1)
                        temp++;
                    if(i < m-1 && grid[i+1][j] == 1)
                        temp++;
                    if(j < n-1 && grid[i][j+1] == 1)
                            temp++;
                    count += (4-temp);
                }
            }
        }
        return count;
    }
};