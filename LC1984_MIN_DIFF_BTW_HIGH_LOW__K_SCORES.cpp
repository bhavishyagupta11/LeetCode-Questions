class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1) return 0;
        sort(nums.begin(),nums.end());
        int mini = INT_MAX;
        int i =0;
        int j = k-1;
        while(j < n)
        {
            int diff = abs(nums[i] - nums[j]);
            mini = min(mini,diff);
            i++;
            j++;
        }
        return mini;
    }
};