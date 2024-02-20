class Solution {
public:
    // int n;
    // vector<vector<vector<int> > > dp;
    // int solve(vector<int> &heights, int i, int bricks, int ladders) {
    //     if(i == n-1)
    //         return i;
        
    //     if(dp[i][bricks][ladders] != -1)
    //         return dp[i][bricks][ladders];

    //     int diff = heights[i+1] - heights[i];
    //     if(diff > 0) {
    //         int ans = i;
    //         if(bricks >= diff)
    //             ans = max(ans, solve(heights, i+1, bricks-diff, ladders));
    //         if(ladders > 0)
    //             ans = max(ans, solve(heights, i+1, bricks, ladders-1));
    //         return dp[i][bricks][ladders] = ans;
    //     }
    //     else
    //         return dp[i][bricks][ladders] = solve(heights, i+1, bricks, ladders);
    // }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // n = heights.size();
        // dp.resize(n+1, vector<vector<int> > (bricks+1, vector<int>(ladders+1, -1)));
        // return solve(heights, 0, bricks, ladders);
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i=0; i<n-1; i++) {
            int diff = heights[i+1] - heights[i];
            if(diff > 0) {
                if(pq.size() < ladders)
                    pq.push(diff);
                else {
                    if(pq.empty() || pq.top() >= diff) 
                        bricks -= diff;
                    else {
                        int poll = pq.top();
                        pq.pop();
                        pq.push(diff);
                        bricks -= poll;
                    }
                    if(bricks < 0)
                        return i;
                }
            }
        }
        return n-1;
    }
};