#include<iostream>
using namespace std;

int singleNumber(int arr[],int n) {
        int ans = 0;

        for(int i = 0;i<n; i++)
        {
            ans = ans ^ arr[i];
        }
        return ans;
    }
    int main()
    {
        int arr[]= {2,3,4,2,4};
        int n = 5;
        int ans = singleNumber(arr,n);
        cout<<"Unique Number is : "<< ans << endl;

        return 0; 
    }