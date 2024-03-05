class Solution {
public:
    int minimumLength(string str) {
        int n = str.length();
        int s = 0;
        int e = n-1;
        
        while(s < e) {
            if(str[s] == str[e]) {
                char ch = str[s];
                while(s<n && str[s] == ch)
                    s++;
                while(e>=0 && str[e] == ch)
                    e--;
            }
            else
                break;
        }
        int ans = e-s+1;
        return (ans <= 0)?0:ans;
    }
};