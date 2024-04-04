class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;
        
        for(char ch: s) {
            if(ch == '(') {
                st.push(ch);
                int temp = st.size();
                ans = max(ans, temp);
            }
            else if(ch == ')') 
                st.pop();
        }
        
        return ans;
    }
};