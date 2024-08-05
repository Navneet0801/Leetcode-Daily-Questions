class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> commutativeSum(n);
        commutativeSum[0] = nums[0];
        for(int i=1; i<n; i++) {
            commutativeSum[i] = commutativeSum[i-1] + nums[i];
        }

        vector<int> subarraySum;
        for(int i=0; i<n; i++) {
            subarraySum.push_back(commutativeSum[i]);
            for(int j=i+1; j<n; j++) {
                int sum = commutativeSum[j] - commutativeSum[i];
                subarraySum.push_back(sum);
            }
        }

        sort(subarraySum.begin(), subarraySum.end());
        int ans = 0;
        int MOD = 1e9+7;
        for(int i=left-1; i<right; i++) {
            ans = (ans + subarraySum[i])%MOD;
        }

        return ans;
    }
};