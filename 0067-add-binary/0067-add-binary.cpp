class Solution {
public:
    void keepSameLen(string &a, string &b) {
        int len = abs(static_cast<int>(a.length() - b.length()));
        if(len == 0)
            return;
        
        string temp = "";
        for(int i=0; i<len; i++)
            temp += '0';
        
        if(a.length() > b.length()) 
            b.insert(0, temp);
        else
            a.insert(0, temp);
    }
    string addBinary(string a, string b) {
        bool carry = 0;
        string ans = "";
        
        keepSameLen(a, b);
        cout << a << " " << b ;
        // return "";
        int n = a.length();
        for(int i=n-1; i>=0; i--) {
            if(a[i] == '1' && b[i] == '1') {
                if(carry)
                    ans += '1';
                else {
                    ans += '0';
                    carry = 1;
                }
            }
            else if(a[i] == '1' || b[i] == '1') {
                if(carry) 
                    ans += '0';
                else 
                    ans += '1';
            }
            else {
                if(carry) {
                    ans += '1';
                    carry = 0;
                }
                else 
                    ans += '0';
            }
        }
        if(carry)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};