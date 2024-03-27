class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            if(nums[i] < k)
                count++;
            
            int j = i+1;
            long long prod = nums[i];
            while(j < n) {
                prod *= nums[j++];
                if(prod < k)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};