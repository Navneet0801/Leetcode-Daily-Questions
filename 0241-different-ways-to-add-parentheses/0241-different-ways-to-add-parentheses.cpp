class Solution {
public:
    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*');
    }
    vector<int> solve(int start, int end, string &str) {
        int len = end-start+1;
        if(len <= 2)
            return {stoi(str.substr(start, len))};
        
        vector<int> ans;
        for(int i=start; i<=end; i++) {
            if(isOperator(str[i])) {
                vector<int> left = solve(start, i-1, str);
                vector<int> right = solve(i+1, end, str);
                char op = str[i];
                
                for(int l: left) {
                    for(int r: right) {
                        if(op == '+')
                            ans.push_back(l+r);
                        else if(op == '-')
                            ans.push_back(l-r);
                        else
                            ans.push_back(l*r);
                    }
                }
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(0, expression.length()-1, expression);
    }
};