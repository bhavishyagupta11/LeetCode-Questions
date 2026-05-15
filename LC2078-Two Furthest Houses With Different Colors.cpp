// LC - 2078 - Two Furthest Houses with Different Colors

// Tc - O(n)
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxIndex = 0;

        for(int i = 0; i < n; i++) {
            if(colors[i] != colors[n - 1]) {
                maxIndex = max(maxIndex, n - 1 - i);
            }

            if(colors[i] != colors[0]) {
                maxIndex = max(maxIndex, i);
            }
        }
        return maxIndex;
    }
};
// O(2n) - Two Pass Solution
// class Solution {
// public:
//     int maxDistance(vector<int>& colors) {
//         int n = colors.size();
//         int maxIndex = 0;
           
//         int i = 0;
//         while(colors[i] == colors[n - 1] && i < n - 1) {
//             i++;
//         }
//         maxIndex = max(maxIndex, n - 1 - i);

//         int j = n - 1;
//         while(colors[0] == colors[j] && j > 0) {
//             j--;
//         }
//         maxIndex = max(maxIndex, j);

//         return maxIndex;
//     }
// };

// O(n^2) - Brute Force
// class Solution {
// public:
//     int maxDistance(vector<int>& colors) {
//         int n = colors.size();
//         int maxIndex = 0;

//         for(int i = 0; i < n; i++) {
//             for(int j = n - 1; j >= 0; j--) {
//                 if(colors[i] != colors[j]) maxIndex = max(maxIndex, j - i);
//                 else continue;
//             }
//         }
//         return maxIndex;
//     }
// };
