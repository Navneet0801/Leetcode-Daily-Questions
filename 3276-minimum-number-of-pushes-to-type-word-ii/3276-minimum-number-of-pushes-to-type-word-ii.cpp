class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;
        for(char ch: word)
            freq[ch]++;
        
        vector<pair<char, int> > Freq;
        for(auto i: freq) {
            Freq.push_back({i.first, i.second});
        }

        sort(Freq.begin(), Freq.end(), [](auto& a, auto& b) {
            return a.second >  b.second;
        });

        int ans = 0;
        int num = 1;
        for(auto i: Freq) {
            if(num <= 8) {
                ans += i.second;
            }
            else if(num > 8 && num <= 16) {
                ans += i.second*2;
            }
            else if(num > 16 && num <= 24)
                ans += i.second*3;
            else
                ans += i.second*4;
            num++;
        }

        return ans;
    }
};