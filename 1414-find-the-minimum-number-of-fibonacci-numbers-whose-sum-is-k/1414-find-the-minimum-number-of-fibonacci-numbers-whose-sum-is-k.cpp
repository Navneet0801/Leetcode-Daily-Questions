class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> series;
        series.push_back(1);
        series.push_back(1);
        
        int a = 1;
        int b = 1;
        int c = 0;
        
        while(c < k) {
            c = a + b;
            a = b;
            b = c;
            
            if(c > k)
                break;
            
            series.push_back(c);
        }
        
        int n = series.size()-1;
        int count = 1;
        int sum = series[n];
        n--;
        
        while(n >= 0) {
            if(sum + series[n] <= k) {
                sum += series[n];
                count++;
            }
            if(sum == k)
                break;
            n--;
        }
        return count;
    }
};