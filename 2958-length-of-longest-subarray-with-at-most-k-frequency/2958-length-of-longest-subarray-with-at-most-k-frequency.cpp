class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int i = 0;
        int j = 0;
        int ans = 0;
        
        while(j < n) {
            freq[nums[j]]++;
            
            while(i < j && freq[nums[j]] > k) {
                freq[nums[i]]--;
                i++;
            }
            
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};