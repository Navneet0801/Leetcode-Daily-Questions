class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i: nums)
            freq[i]++;
        int maxFreq = -1;
        for(auto i: freq) 
            maxFreq = max(maxFreq, i.second);
        int count = 0;
        for(auto i: freq) {
            if(i.second == maxFreq)
                count++;
        }
        return count*maxFreq;
    }
};