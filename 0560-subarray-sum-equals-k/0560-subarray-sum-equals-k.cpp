class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> con(n, 0);
        int sum = 0;
        
        for(int i=0; i<n; i++) {
            sum += nums[i];
            con[i] = sum;
        }
        
        int count = 0;
        for(int i=n-1; i>=0; i--) {
            if(con[i] == k)
                count++;
            
            int j = i-1;
            while(j >= 0) {
                if(con[i] - con[j] == k)
                    count++;
                j--;
            }
        }
        return count;
    }
};