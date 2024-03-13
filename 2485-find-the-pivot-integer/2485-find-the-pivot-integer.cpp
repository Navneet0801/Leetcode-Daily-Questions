class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1)
            return 1;
        
        int total = 0;
        for(int i=1; i<=n; i++)
            total += i;
        
        int currSum = 0;
        for(int i=1; i<=n; i++) {
            currSum += i;
            int rmg = total - currSum + i;
            
            if(currSum == rmg)
                return i;
        }
        return -1;
    }
};