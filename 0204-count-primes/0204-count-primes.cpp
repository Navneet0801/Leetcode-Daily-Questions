class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1)
            return 0;
        
        vector<bool> prime(n, 1);
        for(int p=2; p*p<n; p++) {
            if(prime[p]) {
                for(int i=p*p; i<n; i+=p)
                    prime[i] = 0;
            }
        }
        int count = 0;
        for(int i=2; i<n; i++) {
            if(prime[i])
                count++;
        }
        
        return count;
    }
};