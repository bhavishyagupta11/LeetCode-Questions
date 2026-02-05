class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++) {
            if(nums[i]>0) {
            int rSteps = nums[i] % n;
            int idx = (i + rSteps) % n;
            ans[i] = nums[idx];
            }
            else if(nums[i]==0) {
                ans[i] = nums[i];
            }
            else {
                int lSteps = (-nums[i]) % n;
                int idx = i - lSteps;
                if(idx < 0) idx += n;
                ans[i] = nums[idx];
            } 
        }
        return ans;
    }
};