class Solution {
public:
    bool check(char ch1, char ch2) {
        if(ch1 >= 'a' && ch1 <= 'z' && ch2 >= 'A' && ch2 <= 'Z')
            return 1;
        return 0;
    }
    string makeGood(string s) {
        stack<char> st;
        for(char ch: s) {
            if(st.empty())
                st.push(ch);
            else if(check(ch, st.top())) {
                if((ch - 'a') - (st.top() - 'A') == 0)
                    st.pop();
                else
                    st.push(ch);
            }   
            else if(check(st.top(), ch)) {
                if((st.top() - 'a') - (ch - 'A') == 0)
                    st.pop();
                else
                    st.push(ch);
            }
            else
                st.push(ch);
            
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};