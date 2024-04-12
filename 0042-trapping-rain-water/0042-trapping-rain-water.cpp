class Solution {
public:
    int n;
    void prevMaxElement(vector<int> &height, vector<int> &leftPrev) {
        leftPrev.resize(n, 0);
        int maxi = 0;
        
        for(int i=0; i<n-1; i++) {
            leftPrev[i] = maxi;
            maxi = max(maxi, height[i]);
        }
    }
    void nextMaxElement(vector<int> &height, vector<int> &rightNext) {
        rightNext.resize(n, 0);
        int maxi = 0;
        
        for(int i=n-1; i>0; i--) {
            rightNext[i] = maxi;
            maxi = max(maxi, height[i]);
        }
    }
    int trap(vector<int>& height) {
        n = height.size();
        vector<int> leftPrev;
        vector<int> rightNext;
        
        prevMaxElement(height, leftPrev);
        nextMaxElement(height, rightNext);
        
        vector<int> water(n, 0);
        for(int i=0; i<n; i++) 
            water[i] = min(leftPrev[i], rightNext[i]) - height[i];
        
        int ans = 0;
        for(int i: water) {
            if(i > 0)
                ans += i;
        }
        
        return ans;
    }
};