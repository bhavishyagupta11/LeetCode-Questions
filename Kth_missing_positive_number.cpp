class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;

        while(low<=high) {
            int mid = low+(high-low)/2;
            int missingNums = arr[mid] - (mid+1);
            if(missingNums < k) low = mid + 1;
            else high = mid - 1;
        }
        return high + k + 1; // or low + k;

        // int count = 1;
        // int missingNum = -1;
        // int i = 0;
        // while(k>0) {
        //     if(i<n && arr[i] == count) {
        //         i++;
        //     }
        //     else {
        //         missingNum = count;
        //         k--;
        //     }
        //     count++;
        // }
        // return missingNum;   
    }
};

/////////////// Brute Force with use of hard coding on the basis of the constraints given to us /////////////////

// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int n = arr.size();
//         unordered_set<int>set;
//         vector<int>notFound;
//         for(int i:arr) set.insert(i);
//         for(int i=1;i<=2000;i++) { // Based on the constraints only, use other optimal approach
//             if(!set.count(i)) {
//                 notFound.push_back(i);
//             }
//         }
//         return notFound[k-1];
//     }
// };