class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char>st;
        string ans = "";
        if(num[0]=='0') return "0";
        if(n==k) return "0";
        if(k==0) return num;
        st.push(num[0]);
        for(int i=1;i<n;i++) { 
            while(!st.empty() && k>0 && num[i]<st.top()) {
                st.pop();
                k--; 
            } 
            st.push(num[i]);
        }
        while ( k>0 && !st.empty()) {
                st.pop();
                k--; 
        }
        while(!st.empty()) {
            char top = st.top();
            st.pop();
            ans += top;
        }
        reverse(ans.begin(),ans.end());
        int m = ans.size();
        int idx = 0;
        while(idx<m && ans[idx]=='0') idx++;
        ans = ans.substr(idx);
        return ans.empty()?"0" :ans;
    }
};