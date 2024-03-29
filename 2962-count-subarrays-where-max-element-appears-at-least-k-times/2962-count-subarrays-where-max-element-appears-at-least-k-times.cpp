class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long maxi = *max_element(nums.begin(), nums.end());
        int count = 0;
        int left = 0, right = 0;
        long long ans = 0;
        
        while(right < nums.size() || left > right) {
            if(nums[right] == maxi)
                count++;
            
            while(count >= k) {
                if(nums[left] == maxi)
                    count--;
                left++;
                ans += nums.size()-right;
            }
            right++;
        }
        return ans;
    }
};