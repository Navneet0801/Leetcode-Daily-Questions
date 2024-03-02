class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // sort(begin(nums), end(nums));
        // vector<int> ans;
        // for(int i=1; i<nums.size(); i++){
        //     if(nums[i] == nums[i-1]){
        //         nums[i] = (nums[i-1] + 1 <= nums.size()) ? nums[i-1] + 1 : nums[i-1] - 1;
        //         ans.push_back(nums[i-1]);
        //         ans.push_back(nums[i]);
        //         break;
        //     }
        // }
        // return ans;

        int n = nums.size();
        vector<int> arr(n+1, 0);
        for(int i: nums)
            arr[i]++;
        
        vector<int> ans;
        int extra = 0;
        int missing = 0;
        for(int i=1; i<=n; i++){
            if(arr[i] == 0)
                missing = i;
            if(arr[i] == 2)
                extra = i;
        }
        ans.push_back(extra);
        ans.push_back(missing);

        return ans;
    }
};