class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = nums.size()-1;
        
        while(s < e) {
            if(nums[s] < 0 && abs(nums[s]) == nums[e])
                return nums[e];
            else if(abs(nums[s]) > nums[e])
                s++;
            else
                e--;
        }
        return -1;
    }
};