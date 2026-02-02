// LeetCode Problem - Count Monobit Intergers 
class Solution {
public:
    int countMonobit(int n) {
        int count = 1;
        int x = 1;

        while(x<=n) {
            count++;
            x = (x<<1) | 1;
        }
    return count;
    }
};
