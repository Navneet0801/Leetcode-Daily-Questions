class Solution {
public:
    int compareVersion(string version1, string version2) {
        int version1_temp = 0;
        int version2_temp = 0;
        int i=0, j=0;
        
        while(i < version1.length() || j < version2.length()) {
            while(i < version1.length() && version1[i] != '.') 
                version1_temp = version1_temp*10 + (version1[i++] - '0');
            i++;
            while(j < version2.length() && version2[j] != '.')
                version2_temp = version2_temp*10 + (version2[j++] - '0');
            j++;
            
            if(version1_temp < version2_temp)
                return -1;
            else if(version1_temp > version2_temp)
                return 1;
            else if(i == version1.length() && j == version2.length() && version1_temp == version2_temp)
                return 0;
            else {
                version1_temp = 0;
                version2_temp = 0;
            }
        }
        return 0;
    }
};