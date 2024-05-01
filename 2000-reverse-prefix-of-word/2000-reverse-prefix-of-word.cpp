class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char> s;
        bool flag = 0;
        int i;
        for(i=0; i<word.length(); i++) {
            s.push(word[i]);
            
            if(word[i] == ch) {
                flag = 1;
                i++;
                break;
            }
        }
        if(!flag)
            return word;
        
        string ans = "";
        while(!s.empty()) {
            ans += s.top();
            s.pop();
        }
        
        while(i < word.length())
            ans += word[i++];
        
        return ans;
    }
};