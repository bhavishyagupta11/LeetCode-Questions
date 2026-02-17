// Koko Eating Bananans LeetCode Problem based on Binary Search on Answers

// Famous Interview Question

class Solution {
public:
    int maxNumber(vector<int>&piles, int n) {
        int maxi = INT_MIN;
        for(int num : piles) {
            maxi = max(maxi,num);
        }
        return maxi;
    }
    long long calHour(vector<int>&piles,int n ,int mid) {
        long long hour = 0;
        for(int bananas : piles) {
            hour += ((bananas + mid-1)/mid);
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = maxNumber(piles,n);
        int ans = -1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            long long hours = calHour(piles,n,mid);

            if(hours <= h) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
