class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        int sum = 0;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];

            if(mp.find(sum - k) != mp.end())
                ans += mp[sum-k];
            
            mp[sum]++;
        }
        return ans;
    }
};