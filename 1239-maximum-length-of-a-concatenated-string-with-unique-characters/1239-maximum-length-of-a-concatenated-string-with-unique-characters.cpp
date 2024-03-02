class Solution {
public:
    int solve(int i, vector<string> &arr, vector<string> &strArr, unordered_map<string, int> &dp) {
        if(i >= arr.size())
            return 0;
        
        string str = "";
        for(auto val: strArr)
            str += val;
        if(dp.find(str) != dp.end())
            return dp[str];
        
        
        strArr.push_back(arr[i]);
        unordered_map<char, int> freq;
        for(int i=0; i<strArr.size(); i++) {
            for(int j=0; j<strArr[i].size(); j++) 
                freq[strArr[i][j]]++;
        }
        
        bool flag = 1;
        for(auto val: freq) {
            if(val.second > 1) {
                flag = 0;
                break;
            }
        }
        
        int op1=0, op2=0;
        if(flag)
            op1 = arr[i].size() + solve(i+1, arr, strArr, dp);
        strArr.pop_back();
        op2 = solve(i+1, arr, strArr, dp);
        
        return dp[str] = max(op1, op2);
    }
    int maxLength(vector<string>& arr) {
        vector<string> strArr;
        unordered_map<string, int> dp;
        return solve(0, arr, strArr, dp);
    }
};