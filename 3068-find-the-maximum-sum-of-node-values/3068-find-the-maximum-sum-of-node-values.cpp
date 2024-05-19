class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0;
        vector<int> fayeda;
        
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            fayeda.push_back((nums[i]^k) - nums[i]);
        }
        
        sort(fayeda.begin(), fayeda.end(), greater<int>());
        int n = fayeda.size();
        
        for(int i=0; i<n-1; i+=2) {
            if(fayeda[i] + fayeda[i+1] > 0)
                sum += fayeda[i] + fayeda[i+1];
        }
        
        return sum;
    }
};