class Solution {
public:
    int m, n;
    vector<vector<int> > dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void DFS(vector<vector<int> > &grid, int i, int j, vector<vector<bool> > &vis) {
        if(i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || grid[i][j] == 0)
            return;
        
        vis[i][j] = true;
        for(auto &d : dir) {
            int new_i = i + d[0];
            int new_j = j + d[1];
            DFS(grid, new_i, new_j, vis);
        }
    }

    int numberOfIslands(vector<vector<int>> &grid) {
        vector<vector<bool> > vis(m, vector<bool>(n, false));
        int island = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    DFS(grid, i, j, vis);
                    island++;
                }
            }
        }
        return island;
    }
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int islands = numberOfIslands(grid);
        cout << islands << endl;
        if(islands == 0 || islands > 1) 
            return 0;
        else {
            for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                    if(grid[i][j] == 1) {
                        grid[i][j] = 0;

                        islands = numberOfIslands(grid);
                        if(islands > 1 || islands == 0)
                            return 1;
                        
                        grid[i][j] = 1;
                    }
                }
            }
        }
        return 2;
    }
};