class Solution {
public:
    int prec(char ch) {
        if(ch == '/' || ch == '*')
            return 2;
        else if(ch == '+' || ch == '-')
            return 1;
        else
            return 0;
    }
    int calculate(string s) {
        int n = s.length();
        string postfix = "";
        stack<char> st;
        
        for(char ch: s) {
            if(ch == ' ')
                continue;
            if(isdigit(ch))
                postfix += ch;
            else {
                postfix += '!';
                while(!st.empty() && prec(ch) <= prec(st.top())) {
                    postfix += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        if(postfix.length() > 0)
            postfix += '!';
        
        while(!st.empty()) {
            postfix += st.top();
            st.pop();
        }
        // cout << postfix;
        
        stack<int> st1;
        string tmp = "";
        for(char ch: postfix) {
            if(isdigit(ch))
                tmp += ch;
            else if(ch == '!') {
                int number = stoi(tmp);
                tmp = "";
                st1.push(number);
            }
            else {
                int num = st1.top();
                st1.pop();
                
                if(ch == '+')
                    st1.top() += num;
                else if(ch == '-')
                    st1.top() -= num;
                else if(ch == '*')
                    st1.top() *= num;
                else
                    st1.top() /= num;
            }
        }
        return st1.top();
        
        // return 0;
    }
};