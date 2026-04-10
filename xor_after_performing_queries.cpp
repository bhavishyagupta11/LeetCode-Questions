class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int M = 1e9 + 7;

        for(auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            while(l <= r) {
                nums[l] = (1LL * nums[l] * v) % M;

                l += k;
            }
        }

        int xorRes = 0;

        for(int i = 0; i < nums.size(); i++) {
            xorRes ^= nums[i];
        }
        return xorRes;
    }
};