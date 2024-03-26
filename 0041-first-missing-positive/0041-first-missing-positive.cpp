class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> arr;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] <= 0)
                continue;
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            arr.push_back(nums[i]);
        }
        
        // for(int i=0; i<arr.size(); i++)
        //     cout << arr[i] << " ";
        // cout << endl;
        int temp = 1;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] != temp)
                return temp;
            temp++;
        }
        
        return temp;
        
        // return 0;
    }
};