class Solution {
public:
    int daysCalC(vector<int>& weights, int cap) {
        int load = 0;
        int days = 1;
        for(int i =0;i<weights.size();i++) {
            if(load + weights[i] > cap) {
                days++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = -1;

        while(low<=high) {
            int mid = low+(high-low)/2;

            if(daysCalC(weights,mid) <= days) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        // for(int cap=low;cap<=totalSum;cap++) {
        //     int requiredDays = daysCalC(weights, cap);
        //     if(requiredDays <= days) {
        //         return cap;
        //     }
        // }
        return ans;
    }
};