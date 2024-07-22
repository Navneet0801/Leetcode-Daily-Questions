class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        for(int i=0; i<n; i++) {
            int loc = i;
            for(int j=i+1; j<n; j++) {
                if(heights[j] > heights[loc])
                    loc = j;
            }
            swap(heights[i], heights[loc]);
            swap(names[i], names[loc]);
        }
        return names;
    }
};