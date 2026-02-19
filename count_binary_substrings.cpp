class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int prev = 0;
        int curr = 1;
        int subString = 0;
        for(int i=1;i<n;i++) {
            if(s[i] == s[i-1]) {
                curr++;
            }
            else {
                subString += min(prev,curr);
                prev = curr;
                curr = 1;
            }
        }
        return subString + min(prev,curr);
    }
};