class Solution {
public:
    // void prevHighest(vector<int> &height, vector<int> &left) {
    //     int n = height.size();
    //     left.resize(n, 0);
    //     int maxi = 0;       
    //     for(int i=0; i<n-1; i++) {
    //         left[i] = maxi;
    //         maxi = max(maxi, height[i]);
    //     }
    // }
    // void nextHighest(vector<int> &height, vector<int> &right) {
    //     int n = height.size();
    //     right.resize(n, 0);
    //     int maxi = 0;
    //     for(int i=n-1; i>0; i--) {
    //         right[i] = maxi;
    //         maxi = max(maxi, height[i]);
    //     }
    // }
    int trap(vector<int>& height) {
//         vector<int> left;
//         vector<int> right;
        
//         prevHighest(height, left);
//         nextHighest(height, right);
        
//         int n = height.size();
//         vector<int> water(n, -1);
//         for(int i=1; i<n-1; i++) 
//             water[i] = min(left[i], right[i]) - height[i];
        
//         int ans = 0;
//         for(int i: water) {
//             if(i > 0)
//                 ans += i;
//         }
//         return ans;
        int l = 0;
        int r = height.size()-1;
        int lmax = INT_MIN;
        int rmax = INT_MIN;
        int ans = 0;
        
        while(l < r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            ans += (lmax < rmax) ? lmax-height[l++] : rmax-height[r--];
        }
        return ans;
    }
};