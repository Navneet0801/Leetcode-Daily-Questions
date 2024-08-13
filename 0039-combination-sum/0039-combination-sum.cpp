class Solution {
public:
    vector<vector<int> > ans;
    vector<int> temp;

    void solve(vector<int> &arr, int target, int i) {
        if(i >= arr.size()) {
            if(target == 0)
                ans.push_back(temp);
            return;
        }
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        if(arr[i] <= target) {
            temp.push_back(arr[i]);
            solve(arr, target-arr[i], i);
            temp.pop_back();
        }
        solve(arr, target, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return ans;
    }
};