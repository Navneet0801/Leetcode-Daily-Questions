class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        int f = 0 ;
        int X = 0;
        
        unordered_map<char, int> freq;
        for(char i: tasks) {
            freq[i]++;
            f = max(f, freq[i]);
        }
        
//         map<char, pair<int, int> > countTime;
//         for(auto i: freq) 
//             countTime[i.first] = {i.second, 0}; 
        
//         int time = 0;
//         while(!countTime.empty()) {
//             for(auto i=countTime.begin(); i!=countTime.end();) {
//                 time++;
//                 if(i->second.second == 0 || time - i->second.second > n) {
//                     i->second.second = time;
//                     i->second.first--;
                    
//                     cout << i->first << " - { " << i->second.first << ", " << i->second.second << " }" << endl; 
//                     char curr = i->first;
//                     i++;
                    
//                     if(countTime[curr].first == 0) {
//                         countTime.erase(curr);
//                     }
                    
//                 }
//             }
//         }
//         return time;
        
        for(auto i: freq) {
            if(i.second == f)
                X++;
        }
        
        return max((n+1)*(f-1) + X, size);
    }
};