LeetCode - Find_smallest_letter_greater_than_target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (letters[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (ans == -1) ? letters[0] : letters[ans];

        // char minChar = '{';
        // int n = letters.size();
        // for(int i = 0;i<n;i++) {
        //     if(letters[i]>target) {
        //         minChar = min(minChar,letters[i]);
        //     }
        // }
        // return (minChar=='{')?letters[0]:minChar;
    }
};
