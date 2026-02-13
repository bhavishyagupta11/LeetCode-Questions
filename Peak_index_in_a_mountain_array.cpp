class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        while(s<e)
        {
            int mid = s + (e-s)/2;
            if(arr[mid]>arr[mid+1])
            {
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }
        return s;
        // int e = n-2;
        // int ans = 0;
        // while(s<=e)
        // {
        //     int mid = s + (e-s)/2;
        //     if(arr[mid]>arr[mid+1])
        //     {
        //         ans = mid;
        //         e = mid - 1;
        //     }
        //     else
        //     {
        //         s = mid + 1;
        //     }
        // }
        // return ans;
    }
};