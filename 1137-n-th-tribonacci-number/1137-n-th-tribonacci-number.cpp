class Solution {
public:
//     int solve(int n) {
//         if(n == 0)
//             return 0;
//         if(n == 1)
//             return 1;
//         if(n == 2)
//             return 1;
        
//         return solve(n-1) + solve(n-2) + solve(n-3);
//     }
    int tribonacci(int n) {
        vector<int> arr(38);
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        
        for(int i=3; i<=n; i++) {
            arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        }
        
        return arr[n];
    }
};