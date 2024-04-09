class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int mod = tickets.size();
        int i = 0;
        while(1) {
            int idx = i%mod;
            if(tickets[idx] != 0) {
                tickets[idx]--;
                time++;

                if(tickets[k] == 0)
                    return time;
            }
            i++;
        }
        return 0;
    }
};