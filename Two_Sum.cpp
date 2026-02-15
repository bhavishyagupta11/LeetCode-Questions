// Brute force approach
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int>ans;
//        int n = nums.size();
//        for(int i = 0;i<n ; i++)
//        {
//         for(int j = i+1; j<n; j++)
//         {
//             if(nums[i]+ nums[j]==target)
//             {
//             ans.push_back(i);
//             ans.push_back(j);
//             return ans;
//         }
//        } 
//     }
//        return ans;
// }
// };

// two pointers approach
//class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<pair<int, int>> indexedNums;
        
//         // Store original indices before sorting
//         for (int i = 0; i < nums.size(); i++) {
//             indexedNums.push_back({nums[i], i});
//         }

//         // Sort based on values
//         sort(indexedNums.begin(), indexedNums.end());

//         int l = 0, h = nums.size() - 1;

//         while (l < h) {
//             int curr_sum = indexedNums[l].first + indexedNums[h].first;

//             if (curr_sum == target) {
//                 return {indexedNums[l].second, indexedNums[h].second};
//             } else if (curr_sum < target) {
//                 l++; // Increase sum
//             } else {
//                 h--; // Decrease sum
//             }
//         }
//         return {}; // No solution found
//     }
// };


// optimized approach 
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;  // To store element and its index
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            if (map.find(complement) != map.end()) {
                ans.push_back(map[complement]);
                ans.push_back(i);
                return ans;
            }
            
            map[nums[i]] = i;  // Store the current element and its index
        }
        
        return ans;  // If no solution found
    }
};
