// CODE -2

class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int start = 0;
            int deficit = 0;
            int balance = 0;
    
            for(int i=0; i<gas.size(); i++) {
                if(balance + gas[i] < cost[i]) {
                    //deficit case
                    deficit += balance+gas[i]-cost[i];
                    //deficit case -> aage nahi ja skta , start update
                    start = i+1;
                    //agar deficit exist krta h , toh common sense hai
                    //k balance me koi bhi gas nhi hogi
                    //that swhy balance gain zero kardo
                    balance = 0;
                }
                else {
                    //extra gas bach gyi h, balance me add krdo 
                    balance = balance + gas[i]-cost[i];
                }
            }
            //deficit -> -ve value
            //balance -> +ve value
            //>= 0 -> 0 or extra gas bach jaegi overall -> circle complete
    
            if(balance + deficit >= 0) 
                return start;
            else
                return -1;
        }
    };



// CODE -1 

// #include<iostream>
// #include<vector>
// using namespace std;
// class Solution
// {
//     public:
//     int canCompleteCircuit(vector<int>&gas,vector<int>&cost)
//     {
//     int start = 0; 
//     int balance = 0;
//     int deficit = 0;

//     for(int i =0; i<gas.size();i++)
//     {
//         balance = balance + gas[i] - cost[i];
//         //+ive -> balance hai, nothing to worry about
//         //-ive -> ye deficit ko darsha rha hai
//         if(balance<0)
//         {
//             deficit +=  abs(balance);
        
//         // deficit aaya h iska mtlb,aage nahi ja paye
//         // iska mtlb start update hoga
//         start = i+1;
//         balance = 0;
//         }
//     }
//     if(balance - deficit >= 0)
//         {
//             return start;
//         } 
//     else
//         {
//             return -1;
//         }
    
//     }