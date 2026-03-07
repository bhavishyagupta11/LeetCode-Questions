class Solution {
public:
    int minFlips(string s) {
        int n = s.length();

        // s1 = "10101010..."
        // s2 = "01010101..."

        // string s1,s2;

        // for(int i = 0;i < 2*n ;i++) {
        //     s1 += i % 2 ? '0' : '1';
        //     s2 += i % 2 ? '1' : '0';
        // }
        int result = INT_MAX;
        int flip1 = 0;
        int flip2 = 0;

        int i = 0;
        int j = 0;

        while(j < 2*n) { 
            if(s[j%n] != (j%2 ? '0' : '1')) {
                flip1++;
            }
            // if(s[j] != s2[j]) {
            //     flip2++;
            // }

            if(j-i+1 > n)
            {
                if(s[i%n] != (i%2 ? '0' : '1')) { 
                    flip1--;
                }
                // if(s[i] != s1[i]) {
                //     flip2--;
                // }
                i++;
            }
            flip2 = n - flip1;

            if(j-i+1 == n) {
                result = min({result, flip1, flip2});
            }
            j++;
        }
        return result;
    }
};

///////////// Sliding Window with Extra Space //////////////
// class Solution {
// public:
//     int minFlips(string s) {
//         int n = s.length();
//         s = s + s; // for type 1 operation 
//         // ye dhyaan rkho jb bhi cicular order mei diya jaaye
//         // isee apply krke dekh lekr ek baar

//         // s1 = "10101010..."
           // s2 = "01010101..."

//         string s1,s2;

//         for(int i = 0;i < 2*n ;i++) {
//             s1 += i % 2 ? '0' : '1';
//             s2 += i % 2 ? '1' : '0';
//         }

//         // sliding window concept of i and j
//         // kyunki s+s ki string hmne leli h
//         // to ab m window ko slide krte hue min op check krte jaunga
//         int result = INT_MAX;
//         int flip1 = 0;
//         int flip2 = 0;

//         int i = 0;
//         int j = 0;

//         while(j < 2*n) { // bcoz of size of s + s

//             if(s[j] != s1[j]) {
//                 flip1++;
//             }
//             // if(s[j] != s2[j]) {
//             //     flip2++;
//             // }

//             if(j-i+1 > n) // mtlb window ka size n se jyaada ho gya
//             // to mujhe ab window shrink krni h
//             {
//                 if(s[i] != s1[i]) { 
//                     flip1--;
//                 }
//                 // if(s[i] != s1[i]) {
//                 //     flip2--;
//                 // }
//                 i++;
//             }
//             flip2 = n - flip1;

//             if(j-i+1 == n) {
//                 result = min({result, flip1, flip2});
//             }
//             j++;
//         }
//         return result;
//     }
// };