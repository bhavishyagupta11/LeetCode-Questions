class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0;
        for(int i=0;i<n.length();i++) {
            int num = n[i]-'0';
            maxi = max(maxi,num);
            if(num == 9) return 9;
        }
        return maxi;
    }
};