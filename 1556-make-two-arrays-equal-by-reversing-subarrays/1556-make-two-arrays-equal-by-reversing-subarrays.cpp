class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int i=0; i<arr.size(); i++) {
            freq[arr[i]]++;
        }
        for(int i=0; i<target.size(); i++) {
            int num = target[i];
            if(freq.find(num) == freq.end() || freq[num] == 0)
                return false;
            freq[num]--;
        }

        return true;
    }
};