class Solution {
public:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    string solve(string str) {
        string ans = "";
        if(str == "000" || str == "00" || str == "0")
            return ans;
        reverse(str.begin(), str.end());
        int n = str.length();

        if(n == 3) {
            int hundredth = str[0] - '0';
            if(hundredth != 0)
                ans += (ones[hundredth] + " Hundred ");

            int tenth = str[1] - '0';
            bool flag = false;
            if(tenth == 1) {
                int oneth = str[2] - '0';
                ans += (teens[oneth]);
                flag = true;
            }
            else 
                ans += (tens[tenth] + " ");
            
            if(!flag) {
                int oneth = str[2] - '0';
                ans += (ones[oneth]);
            }
        }

        else if(n == 2) {
            int tenth = str[0] - '0';
            bool flag = false;
            if(tenth == 1) {
                int oneth = str[1] - '0';
                ans += (teens[oneth]);
                flag = true;
            }
            else 
                ans += (tens[tenth] + " ");
            
            if(!flag) {
                int oneth = str[1] - '0';
                ans += (ones[oneth]);
            }
        }
        
        else { 
            int oneth = str[0] - '0';
            ans += (ones[oneth]);
            return ans;
        }

        return ans;
    }

    string removeSpaces(string &ans) {
        string str = "";
        str += ans[0];
        for(int i=1; i<ans.length(); i++) {
            if(ans[i] == ' ' && ans[i-1] == ' ')
                continue;
            else
                str += ans[i];
        }
        return str;
    }

    void removeLeadAndTrail(string &result) {
        int start = 0;
        size_t end = result.size() - 1;
        while (end > start && isspace(static_cast<unsigned char>(result[end]))) {
            --end;
        result = result.substr(start, end - start + 1);
    }
    }

    string numberToWords(int num) {
        if(num == 0)
            return "Zero";

        string ans = "", str = "", billion = "", million = "", thousand = "", last = "";
        int j = 0, k = 0;
        while(num) {
            int digit = num%10;
            num /= 10;
            str += (digit + '0');
            j++;
            if(j == 3) {
                // cout << str << endl;
                string temp = solve(str);
                str = "";
                j = 0;
                k++;

                if(k == 1 && temp.length() != 0)
                    last = temp;
                else if(k == 2 && temp.length() != 0)
                    thousand = temp + " Thousand ";
                else if(k == 3 && temp.length() != 0)
                    million = temp + " Million ";
                else if(k == 4 && temp.length() != 0)
                    billion = temp + " Billion ";
            }
        }
        if(str.length() != 0) {
            k++;
            string temp = solve(str);
            if(k == 1)
                last = temp;
            else if(k == 2)
                thousand = temp + " Thousand ";
            else if(k == 3)
                million = temp + " Million ";
            else
                billion = temp + " Billion ";
        }
        ans = billion + million + thousand + last;
        string result = removeSpaces(ans);
        removeLeadAndTrail(result);
        return result;
    }
    // string numberToWords(int num){
    //     cout << solve("10");
    //     return "";
    // }
};