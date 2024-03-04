class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int start = 0;
        int end = n-1;
        int score = 0;
        int tempScore = 0;
        
        while(start <= end) {
            if(power >= tokens[start]) {
                tempScore++;
                power -= tokens[start++];
                score = max(score, tempScore);
            }
            else {
                if(score > 0) {
                    tempScore--;
                    power += tokens[end--];
                }
                else 
                    return score;
            }
        }
        return score;
    }
};