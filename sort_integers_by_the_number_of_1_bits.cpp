class Solution {
public:
    static int find1BitsCount(int num) {
        int count = 0;
        while(num > 0) {
            num = num & (num - 1);
            count++;
        }
        return count;
    }

    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [](int a, int b) {
            int count_a = find1BitsCount(a);
            int count_b= find1BitsCount(b);
            if (count_a == count_b) return a < b;
            return count_a < count_b;
        };

        sort(arr.begin(), arr.end(), lambda);
        return arr;
    }
};