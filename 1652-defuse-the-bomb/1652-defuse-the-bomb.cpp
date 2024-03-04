class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        
        if(k == 0)
            return ans;
        else if(k > 0) {
            for(int i=0; i<n; i++) {
                int temp = k;
                int j = i+1;
                while(temp--) {
                    int idx = j%n;
                    ans[i] += code[idx];
                    j++;
                }
            }
        }
        else {
            for(int i=0; i<n; i++) {
                int temp = 0;
                int j = i-1;
                while(temp != k) {
                    int idx = j;
                    while(idx < 0)
                        idx += n;
                    ans[i] += code[idx];
                    j--;
                    temp--;
                }
            }
        }
        return ans;
    }
};