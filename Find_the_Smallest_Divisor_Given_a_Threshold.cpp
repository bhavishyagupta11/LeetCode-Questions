class Solution {
public:
    int thresholdCalC(vector<int>& nums, int mid) {
        int thresholdVal = 0;
        for(int i =0;i<nums.size();i++) {
            thresholdVal += ceil(double(nums[i])/mid);
        }
        return thresholdVal;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());

        int low = 1;
        int high = maxi;
        int ans = -1;

        while(low<=high) {
            int mid = low+(high-low)/2;
            if(thresholdCalC(nums,mid)<=threshold) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};