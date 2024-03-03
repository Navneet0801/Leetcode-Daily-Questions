class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int> > ans;
        for(int i=0; i<intervals.size();) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            int j = i+1;
            while(j < intervals.size() && intervals[j][0] <= end) {
                end = max(end, intervals[j][1]);
                j++;
            }
            ans.push_back({start, end});
            i = j;
        }
        return ans;
    }
};