#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(); // rows == columns we have been given
          
        vector<int>endZeroes(n,0);
        // endZeroes[i] = count of consecutive 0s from the end of the ith row

        for(int i=0;i<n;i++) {
            int j = n-1; // start from end to get the trailing zeroes
            int count = 0;
            while(j >= 0 && grid[i][j] == 0) {
                count++;
                j--;
            }

            endZeroes[i] = count;
        }

        int steps = 0;

        for(int i=0;i<n;i++) {
            
            int need = n - i - 1;

            int j = i;

            while(j < n && endZeroes[j] < need) {
                j++;
            }

            if(j==n) return -1;

            steps += j - i;

            while(j > i) {
                swap(endZeroes[j], endZeroes[j-1]);
                j--;
            }
        }
        return steps;
    }
};