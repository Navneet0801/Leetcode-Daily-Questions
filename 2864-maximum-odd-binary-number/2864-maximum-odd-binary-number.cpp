class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int count = 0;
        for(char ch: s) {
            if(ch == '1')
                count++;
        }
        
        string str = "";
        for(int i=0; i<count-1; i++)
            str.push_back('1');
        while(str.length() != n-1)
            str.push_back('0');
        str.push_back('1');
        
        return str;
    }
};