class Solution {
public:
//     void dfs(vector<pair<int, int> > adj[], set<int> &ans, pair<int, int> &i, vector<bool> &vis) {
//         vis[i.first] = 1;
//         ans.insert(i.first);
//         int time = i.second;
            
//         for(auto j: adj[i.first]) {
//             if(j.second >= time && !vis[j.first]) {
//                 dfs(adj, ans, j, vis);
//             }
//         }
//     }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int, int> > adj[n];
        for(int i=0; i<meetings.size(); i++) {
            int u = meetings[i][0];
            int v = meetings[i][1];
            int w = meetings[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
//         set<int> ans;
//         vector<bool> vis(n, 0);
//         ans.insert(0);
//         ans.insert(firstPerson);
        
//         for(auto i: adj[0]) {
//             if(!vis[i.first])
//                 dfs(adj, ans, i, vis);
//         }
        
//         for(auto i: adj[firstPerson]) {
//             if(!vis[i.first])
//                 dfs(adj, ans, i, vis);
//         }
        
//         vector<int> arr;
//         for(auto i: ans)
//             arr.push_back(i);
        
//         return arr;
        
        vector<bool> vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});
        
        while(!pq.empty()) {
            auto i = pq.top();
            int person = i.second;
            int time = i.first;
            pq.pop();
            
            if(vis[person])
                continue;
            vis[person] = 1;
            
            for(auto j: adj[person]) {
                if(!vis[j.first] && j.second >= time)
                    pq.push({j.second, j.first});
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(vis[i])
                ans.push_back(i);
        }
        
        return ans;
    }
};