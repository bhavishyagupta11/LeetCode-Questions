// Lc - 540 , Single Element in a Sorted Array ,Binary Search Pattern Based Question

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<high)
        {
            int mid = low + ( high - low ) /2;

            bool isEven;
            if((high-mid) % 2 == 0) isEven = true;
            else isEven = false;

            if(arr[mid] == arr[mid+1])
            {
                if(isEven) low = mid + 2 ;
                else high = mid-1;
            }
            else { // nums[mid] != nums[mid+1]
                if(isEven) high = mid;
                else low = mid + 1;
            }
        }
        return arr[low];
    }
};