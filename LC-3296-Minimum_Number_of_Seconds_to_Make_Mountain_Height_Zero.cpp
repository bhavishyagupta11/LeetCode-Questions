class Solution {
public:
    long long findHeight(vector<int>& workerTimes, long long checker) {

        long long totalReducedHeight = 0;

        for(int t : workerTimes) {

            long long x = sqrt(2.0 * checker / t + 0.25) - 0.5;

            totalReducedHeight += x;
        }

        return totalReducedHeight;
    }
    ///////////////////// TLE because of the while under for loop ////////////////////
    // long long findHeight(vector<int>& workerTimes, long long checker) {
    //     int n = workerTimes.size();
    //     long long totalReducedHeight = 0;
    //     for(int i=0;i<n;i++) {
    //         if(workerTimes[i] > checker) continue;
    //         else {

    //             long long t = workerTimes[i];

    //             long long x = 0;

    //             while(t * (x + 1) * (x + 2) / 2 <= checker) {
    //                 x++;
    //             }
    //             totalReducedHeight += x;
    //         }
    //     }
    //     return totalReducedHeight;
    // }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        long long low = 1;
        int maxi = *max_element(workerTimes.begin(),workerTimes.end());
        long long high = (long long)maxi * mountainHeight * (mountainHeight + 1) / 2;

        while(low < high) {
            long long mid = low + (high-low)/2;

            if(findHeight(workerTimes, mid) >= mountainHeight) {
                high = mid;
            }
            else low = mid + 1;
        }
        return low;
    }
};