#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        long long len = 0;
        int n = prices.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && prices[i - 1] - prices[i] == 1) {
                len++;          // Extend current descent sequence
            } else {
                len = 1;        // Start new descent sequence
            }
            ans += len;
        }
        return ans;
    }
};
