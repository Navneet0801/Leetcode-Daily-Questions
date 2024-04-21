class Solution {
public:
    bool dfs(unordered_map<int, list<int> > &adj, vector<bool> &vis, int s, int d) {
        if(vis[s])
            return 0;
        vis[s] = 1;
        if(s == d)
            return 1;
        for(int i: adj[s]) {
            if(!vis[i] && dfs(adj, vis, i, d)) 
                return 1;
        }
        return 0;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, list<int> > adj;
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n, 0);
        // for(int i=0; i<n; i++) {
        //     if(!vis[source] && dfs(adj, vis, source, destination))
        //         return 1;
        // }
        
        return dfs(adj, vis, source, destination);
    }
};