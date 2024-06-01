class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        
        for(int i=1; i<s.length(); i++) {
            int num1 = s[i] - 'a';
            int num2 = s[i-1] - 'a';
            sum += abs(num1-num2);
        }
        
        return sum;
    }
};