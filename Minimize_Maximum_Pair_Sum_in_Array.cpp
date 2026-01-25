class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = n-1;
        int maxSum = 0;
        while(i<j)
        {
            int minSum = nums[i] + nums[j];
            maxSum = max(maxSum,minSum);
            i++;
            j--;
        }
        return maxSum;
    }
};
